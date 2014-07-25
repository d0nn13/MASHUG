/*
** xml_spritesheet_handler.c for handlers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG/xml/src/core/handlers
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Jul 16 12:45:49 2014 Samir Ahamada
** Last update Wed Jul 16 12:45:49 2014 Samir Ahamada
*/

/**
 *	@file	xml_spritesheet_handler.c
 *	@brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include "../../base/memory.h"
#include "../log.h"

#include "../handlers.h"

/**
 *	@brief	Parse sprites in spritesheet tree (internal)
 */
static void	xml_spritesheet_sprites(xmlNodePtr node,
					t_spriteholder **s,
					Uint8 *count);

/**
 *	@brief	Copy sprite values to container (internal)
 */
static void	xml_spritesheet_fill_container(xmlAttrPtr att,
					       t_spriteholder *s);

Uint8		xml_spritesheet_callback(xmlNodePtr node, void *container)
{
  Uint8		count;

  count = 0;
  node = node->children ? node->children : NULL;
  while (node)
  {
    if (node->type == XML_ELEMENT_NODE &&
	!xmlStrcmp(node->name, (xmlChar * const)"spr"))
      break ;
    if (!node->children)
      node = node->next;
    else
      node = node->children;
  }
  if(node)
    xml_spritesheet_sprites(node, (t_spriteholder **)container, &count);
  if (container)
    SDL_LogVerbose(XML_LCAT, "xml_spritesheet: %d elements saved", count);
  return (count);
}

static void	xml_spritesheet_sprites(xmlNodePtr node,
					t_spriteholder **s,
					Uint8 *count)
{
  xmlAttrPtr	att;

  while (node)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      if (s)
	s[*count] = mem_alloc(sizeof(t_spriteholder));
      att = node->properties;
      while (att)
      {
	if (s)
	  xml_spritesheet_fill_container(att, s[*count]);
	att = att->next;
      }
      (*count)++;
    }
    node = node->next;
  }
  if (s && s[*count])
    s[*count] = NULL;
}

static void	xml_spritesheet_fill_container(xmlAttrPtr att,
					       t_spriteholder *s)
{
  if (!ptr_chk(s, "spriteholder", XML_LCAT, "xml_spritesheet_fill_container"))
    return ;
  SDL_LogVerbose(XML_LCAT, "xml_spritesheet: saving value '%s' as '%s'",
		 (char *)att->children->content, (char *)att->name);
  if (!xmlStrcmp(att->name, (xmlChar *)"name"))
    strncpy(s->name, (char *)att->children->content, sizeof(s->name));
  else if (!xmlStrcmp(att->name, (xmlChar *)"x"))
    s->rect.x = atoi((char *)att->children->content);
  else if (!xmlStrcmp(att->name, (xmlChar *)"y"))
    s->rect.y = atoi((char *)att->children->content);
  else if (!xmlStrcmp(att->name, (xmlChar *)"w"))
    s->rect.w = atoi((char *)att->children->content);
  else if (!xmlStrcmp(att->name, (xmlChar *)"h"))
    s->rect.h = atoi((char *)att->children->content);
}

