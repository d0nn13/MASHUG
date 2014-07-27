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

static void	silent_xml(void *, char const *, ...);

Uint8		xml_parse(char const *path, t_xmlcallback callback, void *container)
{
  xmlDocPtr	doc;
  xmlNodePtr	node;

  xmlSetGenericErrorFunc(NULL, &silent_xml);
  if (!ptr_chk(path, "xml path", XML_LCAT, "xml_parse") ||
      !ptr_chk(&callback, "callback", XML_LCAT, "xml_parse"))
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
  return (callback(node, container));
}

static void	silent_xml(void *ctx, char const *msg, ...)
{
  (void)ctx;
  (void)msg;
}
