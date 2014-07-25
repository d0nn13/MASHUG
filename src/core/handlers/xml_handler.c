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
  {&xml_hiscore_callback, "<!DOCTYPE hiscores SYSTEM \"dtd/hiscores.dtd\">"},
  {&xml_spritesheet_callback, "<!DOCTYPE img SYSTEM \"../spritesheet.dtd\">"}
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
static Uint8	xml_validate(xmlDocPtr doc);

/*
 *	@brief	libxml2 error silencing callback
 */
static void	xml_silent(void *, char const *, ...);

Uint8		xml_parse(char const *path, t_xml_type t, void *container)
{
  xmlDocPtr	doc;
  xmlNodePtr	node;

  xmlSetGenericErrorFunc(NULL, &xml_silent);
  if (!ptr_chk(path, "xml path", XML_LCAT, "xml_parse") ||
      !ptr_chk(&types[t].call, "callback", XML_LCAT, "xml_parse"))
    return (0);
  if (!(doc = xmlParseFile(path)))
  {
    SDL_LogCritical(XML_LCAT, "Couldn't parse XML file");
    return (0);
  }
  if (!(node = xmlDocGetRootElement(doc)))
  {
    SDL_LogCritical(XML_LCAT, "Couldn't get XML root element");
    return (0);
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

static Uint8		xml_validate(xmlDocPtr doc)
{
  xmlValidCtxtPtr	ctxt;
  Uint8			r;

  ctxt = xmlNewValidCtxt();
  if (!ptr_chk(ctxt, "ctxt", XML_LCAT, "xml_validate"))
  {
    SDL_LogError(XML_LCAT, "Couldn't validate XML file");
    return (0);
  }
  if ((r = xmlValidateDocument(ctxt, doc)))
    SDL_LogVerbose(XML_LCAT, "xml_validate: '%s' has been validated",
		   (char *)doc->name);
  else
    SDL_LogError(XML_LCAT, "Couldn't validate XML file");
  free(ctxt);
  return (r);
}

static void	xml_silent(void *ctx, char const *msg, ...)
{
  (void)ctx;
  (void)msg;
}
