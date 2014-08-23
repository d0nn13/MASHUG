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
#include <errno.h>
#include <libxml/parser.h>
#include "../../base/memory.h"
#include "../log.h"

#include "../handlers.h"

/* TODO (ahamad_s): retrieve spritesheet image from XML file */

/**
 *	@brief	Parse sprites in spritesheet tree (internal)
 */
static void	xml_spritesheet_sprites(xmlNodePtr node,
					t_spritesheet *ss,
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
  for (; node; node = !node->children ? node->next : node->children)
  {
    if (node->type == XML_ELEMENT_NODE &&
	!xmlStrcmp(node->name, (xmlChar *)"spr"))
      break ;
  }
  if(node)
    xml_spritesheet_sprites(node, (t_spritesheet *)container, &count);
  if (container)
    SDL_LogVerbose(XML_LCAT, "xml_spritesheet: %d elements saved", count);
  return (count);
}

static void	xml_spritesheet_sprites(xmlNodePtr node,
					t_spritesheet *ss,
					Uint8 *count)
{
  xmlAttrPtr		att;
  t_spriteholder	**s;

  s = NULL;
  for (; node; node = node->next)
  {
    if (node->type == XML_ELEMENT_NODE)
    {
      if (ss)
      {
	s = ss->sprites;
	s[*count] = mem_alloc(sizeof(t_spriteholder));
	s[*count]->sheet = ss;
      }
      for (att = node->properties; att; att = att->next)
	if (ss && s)
	  xml_spritesheet_fill_container(att, s[*count]);
      (*count)++;
    }
  }
  if (s && s[*count])
    s[*count] = NULL;
}

static void	xml_spritesheet_fill_container(xmlAttrPtr att,
					       t_spriteholder *s)
{
  char		*content;
  char		*err;

  content = (char *)att->children->content;
  errno = 0;
  err = "";
  if (!ptr_chk(s, "spriteholder", XML_LCAT, "xml_spritesheet_fill_container"))
    return ;
  if (!xmlStrcmp(att->name, (xmlChar *)"name"))
  {
    s->name = mem_alloc((strlen(content) + 1));
    strcpy(s->name, content);
  }
  else if (!xmlStrcmp(att->name, (xmlChar *)"x"))
    s->rect.x = strtol(content, &err, 10);
  else if (!xmlStrcmp(att->name, (xmlChar *)"y"))
    s->rect.y = strtol(content, &err, 10);
  else if (!xmlStrcmp(att->name, (xmlChar *)"w"))
    s->rect.w = strtol(content, &err, 10);
  else if (!xmlStrcmp(att->name, (xmlChar *)"h"))
    s->rect.h = strtol(content, &err, 10);
  if (errno == EINVAL || errno == ERANGE || strlen(err))
    SDL_LogError(XML_LCAT, "xml_spritesheet: error while saving '%s' as '%s'",
		 content, (char *)att->name);
  else
    SDL_LogVerbose(XML_LCAT, "xml_spritesheet: saved value '%s' as '%s'",
		   content, (char *)att->name);
}
