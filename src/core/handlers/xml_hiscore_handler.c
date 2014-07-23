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

static void	xml_hiscore_entries(xmlNodePtr node,
				    t_hiscoreholder *container,
				    Uint8 *count);
static void	xml_hiscore_fill_container(xmlAttrPtr, t_hiscoreholder *);

static xmlChar	game[GAME_NAME_LENGTH] = "";

Uint8		xml_hiscore_callback(xmlNodePtr node, void *container)
{
  xmlAttrPtr	att;
  xmlNodePtr	entry;
  Uint8		count;

  count = 0;
  if (xmlStrcmp(node->name, (const xmlChar *)"hiscores"))
  {
    SDL_LogError(XML_LCAT, "Wrong hiscores file");
    return (0);
  }
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

static void	xml_hiscore_entries(xmlNodePtr node, t_hiscoreholder *container, Uint8 *count)
{
  xmlAttrPtr	att;

  while (node)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      att = node->properties;
      if (xmlStrcmp(node->name, (const xmlChar *)"entry"))
	return ;
      att = node->properties;
      while (att)
      {
	if (container)
	  xml_hiscore_fill_container(att, &container[*count]);
	att = att->next;
      }
      (*count)++;
    }
    node = node->next;
  }
}

static void	xml_hiscore_fill_container(xmlAttrPtr att, t_hiscoreholder *holder)
{
  if (!xmlStrcmp(att->name, (xmlChar *)"nickname"))
    strncpy(holder->nickname, (char *)att->children->content,
	sizeof(holder->nickname));
  else if (!xmlStrcmp(att->name, (xmlChar *)"score"))
    holder->score = atoi((char *)att->children->content);
  else if (!xmlStrcmp(att->name, (xmlChar *)"date"))
    holder->date = atoi((char *)att->children->content);
}

void	xml_hiscore_set_game_filter(const char *name)
{
  if (!ptr_chk(name, "game filter", XML_LCAT, "xml_hiscore_set_game_filter"))
    return ;
  strncpy((char *)game, name, GAME_NAME_LENGTH);
}
