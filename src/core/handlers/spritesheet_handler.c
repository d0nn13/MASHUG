/*
** spritesheet_handler.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Wed Jul 23 12:51:23 2014 Emmanuel Atse
*/

/**
 *	@file	spritesheet_handler.c
 *	@brief	Spritesheet handling interface
 */

#include <SDL2/SDL_image.h>
#include "../../base/memory.h"
#include "../log.h"
#include "../renderer.h"

#include "../handlers.h"

t_spritesheet	*make_spritesheet(char const *img, char const *xml)
{
  t_spritesheet	*ss;
  SDL_Surface	*surface;
  Sint8		sprite_count;

  surface = IMG_Load_RW(SDL_RWFromFile(img, "rb"), 1);
  if (!ptr_chk(surface, "surface", SPR_LCAT, "make_spritesheet"))
      return (NULL);
  if ((sprite_count = xml_parse(xml, SHEET_XML, NULL)) <= 0)
    return (NULL);
  ss = mem_alloc(1, sizeof(t_spritesheet));
  ss->tex = make_texture_from_surface(get_renderer(), surface);
  SDL_FreeSurface(surface);
  ss->sprites = mem_alloc(sprite_count + 1, sizeof(t_spriteholder *));
  xml_parse(xml, SHEET_XML, ss);
  SDL_LogDebug(SPR_LCAT, "make_spritesheet: loaded '%s' with data from '%s'",
	       img, xml);
  return (ss);
}

t_spriteholder const	*get_sprite(t_spritesheet const *ss, char const *name)
{
  t_spriteholder	**sprites;

  if (!ptr_chk(ss, "spritesheet", SPR_LCAT, "get_sprite") ||
      !ptr_chk(name, "name", SPR_LCAT, "get_sprite") ||
      !ptr_chk(ss->sprites, "spritesheet->sprites", SPR_LCAT, "get_sprite"))
    return (NULL);
  sprites = ss->sprites;
  while (*sprites)
  {
    if (strcmp(name, (*sprites)->name) == 0)
      return (*sprites);
    ++sprites;
  }
  return (NULL);
}

void			free_spritesheet(t_spritesheet *ss)
{
  t_spriteholder	**sh;

  if (!ptr_chk(ss, "spritesheet", SPR_LCAT, "free_spritesheet"))
    return ;
  sh = ss->sprites;
  while (*sh)
  {
    mem_free((*sh)->name);
    mem_free(*sh++);
  }
  mem_free(ss->sprites);
  free_texture(ss->tex);
  mem_free(ss);
  SDL_LogDebug(SPR_LCAT, "free_spritesheet: sprites destroyed");
}
