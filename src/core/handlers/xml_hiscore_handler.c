/*
** xml_hiscore_handler.c for handlers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core/handlers
**
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat Jul 12 17:43:36 2014 Samir Ahamada
** Last update Wed Jul 23 17:08:36 2014 ENNEBATI Yassine
*/

/**
 *	@file	xml.c
 *	@brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libxml/parser.h>
#include "../../base/memory.h"
#include "../log.h"

#include "../handlers.h"

/**
 *	@brief	Parse entries in hiscore tree (internal)
 */
static void	xml_hiscore_entries(xmlNodePtr node,
				    t_hiscoreholder *h,
				    Uint8 *count);

/**
 *	@brief	Copy entry values to container (internal)
 */
static void	xml_hiscore_fill_container(xmlAttrPtr att, t_hiscoreholder *h);

static char const	*game = "";

Uint8		xml_hiscore_callback(xmlNodePtr node, void *container)
{
  xmlAttrPtr	att;
  xmlNodePtr	entry;
  Uint8		count;

  count = 0;
  node = node->children ? node->children : NULL;
  for (; node; node = node->next)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      att = node->properties;
      if (!xmlStrcmp(att->children->content, (xmlChar *)game) || !strlen(game))
      {
	entry = node->children->next;
	xml_hiscore_entries(entry, (t_hiscoreholder *)container, &count);
      }
    }
  }
  if (container)
    SDL_LogVerbose(XML_LCAT, "xml_hiscores: %d elements saved", count);
  return (count);
}

static void	xml_hiscore_entries(xmlNodePtr node,
				    t_hiscoreholder *h,
				    Uint8 *count)
{
  xmlAttrPtr	att;

  for (; node; node = node->next)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      for (att = node->properties; att; att = att->next)
	if (h)
	  xml_hiscore_fill_container(att, &h[*count]);
      (*count)++;
    }
  }
}

static void	xml_hiscore_fill_container(xmlAttrPtr att, t_hiscoreholder *h)
{
  char		*content;
  char		*err;

  content = (char *)att->children->content;
  errno = 0;
  err = "";
  if (!ptr_chk(h, "hiscoreholder", XML_LCAT, "xml_hiscore_fill_container"))
    return ;
  if (!xmlStrcmp(att->name, (xmlChar *)"nickname"))
  {
    h->nickname = mem_alloc(1, (strlen(content) + 1));
    strcpy(h->nickname, content);
  }
  else if (!xmlStrcmp(att->name, (xmlChar *)"score"))
    h->score = strtol(content, &err, 10);
  if (errno == EINVAL || errno == ERANGE || strlen(err))
    SDL_LogError(XML_LCAT, "xml_hiscores: error while saving '%s' as '%s'",
		 content, (char *)att->name);
  else
    SDL_LogVerbose(XML_LCAT, "xml_hiscores: saved value '%s' as '%s'",
		   content, (char *)att->name);
}

void	xml_hiscore_set_game_filter(char const *name)
{
  if (!ptr_chk(name, "game filter", XML_LCAT, "xml_hiscore_set_game_filter"))
    return ;
  game = name;
}
