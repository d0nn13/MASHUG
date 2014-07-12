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

Uint8		xml_parse(const char *path, t_xmlcallback callback, void *container)
{
  xmlDocPtr	doc;
  xmlNodePtr	node;

  if (!ptr_chk(path, "xml path", XML_LCAT, "xml_parse") ||
      !ptr_chk(&callback, "callback", XML_LCAT, "xml_parse"))
    return (0);
  if (!(doc = xmlParseFile(path)))
    return (1);
  if (!(node = xmlDocGetRootElement(doc)))
    return (1);
  return (callback(node, container));
}
