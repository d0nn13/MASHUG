/*
** xml_handler.c for handlers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core/handlers
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat Jul 12 17:22:40 2014 Samir Ahamada
** Last update Sat Jul 12 17:22:40 2014 Samir Ahamada
*/

/**
 *	@file	xml_handler.c
 *	@brief
 */

#include <libxml/parser.h>
#include "../log.h"

#include "../handlers.h"

static t_xml_typeholder	const	types[] = {
  {
    &xml_hiscore_callback,
    "media/dtd/hiscores.dtd",
    "<!DOCTYPE hiscores SYSTEM \"dtd/hiscores.dtd\">"
  },
  {
    &xml_spritesheet_callback,
    "media/dtd/spritesheet.dtd",
    "<!DOCTYPE img SYSTEM \"../spritesheet.dtd\">"
  }
};

/**
 *	@brief	Checks if the XML file contains an DTD reference 
 *
 *	@return	Zero if the file contains a DTD reference, 1 otherwise
 */
static Uint8	xml_check_dtd(char const *path, t_xml_type t);

/**
 *	@brief	Inject the proper DTD reference in an XML file
 */
static void	xml_inject_dtd(char const *path, t_xml_type t);

/*
 *	@brief	Validates an XML file with DTD informations
 *	@return	1 if the XML file is valid, 0 otherwise
 */
static Uint8	xml_validate(xmlDocPtr doc, t_xml_type t);

/*
 *	@brief	libxml2 error silencing callback
 */
static void	xml_silent(void *, char const *, ...);

Sint8		xml_parse(char const *path, t_xml_type t, void *container)
{
  xmlDocPtr	doc;
  xmlNodePtr	node;

  xmlSetGenericErrorFunc(NULL, &xml_silent);
  if (!ptr_chk(path, "xml path", XML_LCAT, "xml_parse") ||
      !ptr_chk(&types[t].call, "callback", XML_LCAT, "xml_parse"))
    return (-1);
  if (!(doc = xmlParseFile(path)))
  {
    SDL_LogCritical(XML_LCAT, "Couldn't parse XML file");
    return (-2);
  }
  if (xml_check_dtd(path, t))
    xml_inject_dtd(path, t);
  if (xml_validate(doc, t) != 1)
    return (-3);
  if (!(node = xmlDocGetRootElement(doc)))
  {
    SDL_LogCritical(XML_LCAT, "Couldn't get XML root element");
    return (-4);
  }
  return (types[t].call(node, container));
}

static Uint8	xml_check_dtd(char const *path, t_xml_type t)
{
  (void)path;
  (void)t;
  return (1);
}

static void	xml_inject_dtd(char const *path, t_xml_type t)
{
  (void)path;
  (void)t;
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
