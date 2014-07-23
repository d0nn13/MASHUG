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
#include <libxml/parser.h>
#include "../log.h"

#include "../handlers.h"

#define GAME_NAME_LENGTH	15

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

static xmlChar	game[GAME_NAME_LENGTH] = "";

/* TODO: Uncomment DTD inject when ibra has done it */
Uint8		xml_hiscore_callback(xmlNodePtr node, void *container)
{
  xmlAttrPtr	att;
  xmlNodePtr	entry;
  Uint8		count;

  count = 0;
/*   if (xml_hiscore_inject_dtd()) */
/*	return (0); */
  node = node->children ? node->children : NULL;
  while (node)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      att = node->properties;
      if (!xmlStrcmp(att->children->content, game) || !xmlStrlen(game))
      {
	entry = node->children->next;
	xml_hiscore_entries(entry, (t_hiscoreholder *)container, &count);
      }
    }
    node = node->next;
  }
  return (count);
}

static void	xml_hiscore_entries(xmlNodePtr node,
				    t_hiscoreholder *h,
				    Uint8 *count)
{
  xmlAttrPtr	att;

  while (node)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      if (xmlStrcmp(node->name, (xmlChar const *)"entry"))
	return ;
      att = node->properties;
      while (att)
      {
	if (h)
	  xml_hiscore_fill_container(att, &h[(*count)++]);
	att = att->next;
      }
    }
    node = node->next;
  }
}

static void	xml_hiscore_fill_container(xmlAttrPtr att, t_hiscoreholder *h)
{
  if (!ptr_chk(h, "hiscoreholder", XML_LCAT, "xml_hiscore_fill_container"))
    return ;
  SDL_LogVerbose(XML_LCAT, "xml_hiscore: saving value '%s' as '%s'",
		 (char *)att->children->content, (char *)att->name);
  if (!xmlStrcmp(att->name, (xmlChar *)"nickname"))
    strncpy(h->nickname, (char *)att->children->content,
	    sizeof(h->nickname));
  else if (!xmlStrcmp(att->name, (xmlChar *)"score"))
    h->score = atoi((char *)att->children->content);
  else if (!xmlStrcmp(att->name, (xmlChar *)"date"))
    h->date = atoi((char *)att->children->content);
}

void	xml_hiscore_set_game_filter(char const *name)
{
  if (!ptr_chk(name, "game filter", XML_LCAT, "xml_hiscore_set_game_filter"))
    return ;
  strncpy((char *)game, name, GAME_NAME_LENGTH);
}
