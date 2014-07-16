/*
** sprite_handler.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Wed Jul 16 12:52:45 2014 Emmanuel Atse
*/

/**
 *	@file	sprite_handler.c
 *	@brief	Sprite handling interface
 */

#include <SDL2/SDL_image.h>
#include "../log.h"
#include "../renderer.h"
#include "../helpers.h"

#include "../handlers.h"

/* TODO (ahamad_s): Split in 2 functions(?) */
t_texture	*make_sprite(char const *file,
			     SDL_Rect const *zone,
			     SDL_Rect const *size)
{
  SDL_Surface	*sprite;
  SDL_Surface	*spritesheet;
  t_texture	*out;
  SDL_Rect	*s;

  if (!ptr_chk(file, "file", SPR_LCAT, "make_sprite") ||
      !ptr_chk(zone, "zone", SPR_LCAT, "make_sprite"))
    return (NULL);
  spritesheet = IMG_Load_RW(SDL_RWFromFile(file, "rb"), 1);
  s = ((SDL_Rect *)size == NULL) ? (SDL_Rect *)zone : (SDL_Rect *)size;
  if (!spritesheet)
  {
    SDL_LogError(SPR_LCAT, "make_sprite: ", IMG_GetError());
    return (NULL);
  }
  SDL_SetSurfaceBlendMode(spritesheet, SDL_BLENDMODE_NONE);
  sprite = SDL_CreateRGBSurface(0, s->w, s->h, 32,
				RMASK, GMASK, BMASK, AMASK);
  SDL_BlitScaled(spritesheet, zone, sprite, NULL);
  SDL_FreeSurface(spritesheet);
  out = make_texture_from_surface(get_renderer(), sprite);
  SDL_FreeSurface(sprite);
  return (out);
}

void	draw_sprite(t_texture const *s, SDL_Rect const *zone)
{
  if (!ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite"))
    return ;
  SDL_RenderCopy(get_renderer(), s->tex, NULL, zone);
  SDL_RenderPresent(get_renderer());
  SDL_LogDebug(SPR_LCAT, "Drawn sprite");
}

void		draw_sprite_raw(t_texture const *s, SDL_Point const *orig)
{
  SDL_Rect	rect;

  if (!ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite_raw") ||
      !ptr_chk(orig, "origin", SPR_LCAT, "draw_sprite_raw"))
    return ;
  rect = rect_factory(orig->x, orig->y, s->w, s->h);
  draw_sprite(s, &rect);
}

t_spriteholder		*get_sprite(t_spritesheet const *ss, char const *name)
{
  t_spriteholder	**sprites;

  if (!ptr_chk(ss, "spritesheet", GFX_LCAT, "get_sprite") ||
      !ptr_chk(name, "name", GFX_LCAT, "get_sprite") ||
      !ptr_chk(ss->sprites, "spritesheet->sprites", GFX_LCAT, "get_sprite"))
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
