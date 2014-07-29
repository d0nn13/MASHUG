/*
** xml_handler.c for handlers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core/handlers
**
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat Jul 12 17:22:40 2014 Samir Ahamada
** Last update Sat Jul 26 20:19:48 2014 FOFANA Ibrahim
*/

/**
 *	@file	xml_handler.c
 *	@brief
 */

#include <libxml/parser.h>
#include "../../base/memory.h"
#include "../log.h"
#include "../helpers.h"

#include "../handlers.h"

static t_xml_typeholder	const	types[] = {
  {
    &xml_hiscore_callback,
    "media/dtd/hiscores.dtd",
    "<!DOCTYPE hiscores SYSTEM \"dtd/hiscores.dtd\">\n"
  },
  {
    &xml_spritesheet_callback,
    "media/dtd/spritesheet.dtd",
    "<!DOCTYPE img SYSTEM \"../dtd/spritesheet.dtd\">\n"
  }
};

/**
 *	@brief	Checks if the XML file contains an DTD reference
 *
 *	@return	Zero if the file contains a DTD reference, 1 otherwise
 */
static Uint8	xml_check_dtd(char const *path);

/**
 *	@brief	Inject the proper DTD reference in an XML file
 */
static void	xml_inject_dtd(char const *path, t_xml_type t);

/**
 *	@brief	Validates an XML file with DTD informations
 *	@return	1 if the XML file is valid, 0 otherwise
 */
static Uint8	xml_validate(xmlDocPtr doc, t_xml_type t);

/**
 *	@brief	libxml2 error silencing callback
 */
static void	xml_silent(void *, char const *, ...);

Sint8		xml_parse(char const *path, t_xml_type t, void *container)
{
  xmlDocPtr	doc;
  xmlNodePtr	node;
  Sint8		ret;

  xmlSetGenericErrorFunc(NULL, &xml_silent);
  if (!ptr_chk(path, "xml path", XML_LCAT, "xml_parse") ||
      !ptr_chk(&types[t].call, "callback", XML_LCAT, "xml_parse"))
    return (-1);
  if (!(doc = xmlParseFile(path)))
  {
    SDL_LogCritical(XML_LCAT, "Couldn't parse XML file");
    return (-2);
  }
  if (!xml_check_dtd(path))
    xml_inject_dtd(path, t);
  if (xml_validate(doc, t) != 1)
    return (-3);
  if (!(node = xmlDocGetRootElement(doc)))
  {
    SDL_LogCritical(XML_LCAT, "Couldn't get XML root element");
    return (-4);
  }
  ret = types[t].call(node, container);
  xmlFreeDoc(doc);
  return (ret);
}

static Uint8	xml_check_dtd(char const *path)
{
  char		**file;
  Uint32	i;
  Uint16	has_dtd;

  has_dtd = 0;
  file = file_to_tab(path);
  if (!ptr_chk(file, "file", XML_LCAT, "xml_check_dtd"))
    return (0);
  for (i = 0; file[i]; ++i)
  {
    if (strstr(file[i], "<!DOCTYPE "))
    {
      has_dtd = 1;
      SDL_LogVerbose(XML_LCAT, "xml_dtd_check: DTD subset found");
    }
  }
  free_filetab(file);
  return (has_dtd);
}

static void	xml_inject_dtd(char const *path, t_xml_type t)
{
  FILE		*file_out;
  char		**file;
  Uint32	nb_lines;

  file = file_to_tab(path);
  if (!ptr_chk(file, "file", XML_LCAT, "xml_inject_dtd"))
    return ;
  file_out = fopen(path, "w+");
  nb_lines = 0;
  fputs(file[nb_lines++], file_out);
  fputs(types[t].dtd_str, file_out);
  while (file[nb_lines])
    fputs(file[nb_lines++], file_out);
  free_filetab(file);
  fclose(file_out);
  SDL_LogVerbose(XML_LCAT, "xml_inject_dtd: DTD injection done");
}

static Uint8		xml_validate(xmlDocPtr const doc, t_xml_type t)
{
  xmlValidCtxtPtr	ctxt;
  xmlDtdPtr		dtd;
  Uint8			r;

  ctxt = NULL;
  dtd = NULL;
  r = 1;
  ctxt = xmlNewValidCtxt();
  dtd = xmlParseDTD(NULL, (xmlChar *)types[t].dtd_file);
  if (!ptr_chk(ctxt, "ctxt", XML_LCAT, "xml_validate") ||
      !ptr_chk(dtd, "dtd", XML_LCAT, "xml_validate"))
    r = 0;
  if (r && (r = xmlValidateDtd(ctxt, doc, dtd)) == 1)
    SDL_LogVerbose(XML_LCAT, "xml_validate: '%s' has been validated",
		   doc->URL);
  else
    SDL_LogError(XML_LCAT, "xml_validate: couldn't validate XML file '%s'",
		 doc->URL);
  if (ctxt)
    xmlFreeValidCtxt(ctxt);
  if (dtd)
    xmlFreeDtd(dtd);
  return (r);
}

static void	xml_silent(void *ctx, char const *msg, ...)
{
  (void)ctx;
  (void)msg;
}
