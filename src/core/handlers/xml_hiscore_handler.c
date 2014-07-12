/*
** xml_hiscore_handler.c for handlers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core/handlers
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat Jul 12 17:43:36 2014 Samir Ahamada
** Last update Sat Jul 12 17:43:36 2014 Samir Ahamada
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

static void	xml_hiscore_entries(xmlNodePtr, t_hiscoreholder *, Uint8 *);
static void	xml_hiscore_fill_container(xmlAttrPtr, t_hiscoreholder *);

static xmlChar	game_name[15] = "";

Uint8	xml_hiscore_callback(xmlNodePtr node, void *container)
{
  xmlAttrPtr	att;
  xmlNodePtr	entry;
  Uint8		count;

  count = 0;
  if (xmlStrcmp(node->name, (const xmlChar *)"hiscores"))
    return (0);
  node = node->children ? node->children : NULL;
  while (node)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      att = node->properties;
      if (!xmlStrcmp(att->children->content, game_name) || !xmlStrlen(game_name))
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

void	xml_hiscore_set_game_name(const char *name)
{
  if (!ptr_chk(name, "game name", XML_LCAT, "xml_hiscore_set_game_name"))
    return ;
  strcpy((char *)game_name, name);
}
