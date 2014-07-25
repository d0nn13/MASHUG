/*
** sprite_handler.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Wed Jul 23 12:51:23 2014 Emmanuel Atse
*/

/**
 *	@file	sprite_handler.c
 *	@brief	Sprite handling interface
 */

#include <SDL2/SDL_image.h>
#include "../../base/memory.h"
#include "../renderer.h"
#include "../handlers.h"
#include "../helpers.h"
#include "../log.h"


/**
 * TODO: Implement sprite loading from xml parsing
 */
t_spritesheet	*make_spritesheet(const char *file)
{
  t_spritesheet	*ss;
  SDL_Surface	*surface;

  ss = mem_alloc(sizeof(t_spritesheet));
  surface = IMG_Load_RW(SDL_RWFromFile(file, "rb"), 1);
  ss->tex = make_texture_from_surface(get_renderer(), surface);
  SDL_FreeSurface(surface);
  return (ss);
}

void		draw_sprite(t_spritesheet const *ss,
			    t_spriteholder const *s,
			    SDL_Rect const *zone)
{
  SDL_Renderer	*renderer;

  if (!ptr_chk(ss, "spritesheet", SPR_LCAT, "draw_sprite") ||
      !ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite"))
    return ;
  renderer = get_renderer();
  SDL_RenderCopy(renderer, ss->tex->tex, &s->rect, zone);
  SDL_RenderPresent(renderer);
  SDL_LogDebug(SPR_LCAT, "Drawn sprite");
}

void		draw_sprite_raw(t_spritesheet const *ss,
				t_spriteholder const *s,
				SDL_Point const *orig)
{
  SDL_Rect	rect;

  if (!ptr_chk(ss, "spritesheet", SPR_LCAT, "draw_sprite_raw") ||
      !ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite_raw") ||
      !ptr_chk(orig, "origin", SPR_LCAT, "draw_sprite_raw"))
    return ;
  rect = rect_factory(orig->x, orig->y, s->rect.w, s->rect.h);
  draw_sprite(ss, s, &rect);
}

t_spriteholder		*get_sprite(t_spritesheet const *ss, char const *name)
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
    mem_free(*sh++);
  mem_free(ss->sprites);
  free_texture(ss->tex);
  mem_free(ss);
}
