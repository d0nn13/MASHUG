/*
** sprite_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Thu Jun 26 18:47:55 2014 AHAMADA Samir
*/

/**
 *	@file	sprite_handler.c
 *	@brief	Sprite handling interface
 */

#include <SDL2/SDL_image.h>
#include "../log.h"
#include "../renderer.h"

#include "../handlers.h"

/* TODO (ahamad_s): Split in 2 functions(?) */
t_texture	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size)
{
  SDL_Surface	*sprite;
  SDL_Surface	*spritesheet;
  t_texture	*out;
  SDL_Rect	*s;

  if (!file || !zone)
    {
      SDL_LogError(SPR_LCAT, "make_sprite: file and/or zone is/are NULL");
      return (NULL);
    }
  spritesheet = IMG_Load_RW(SDL_RWFromFile(file, "rb"), 1);
  s = (size == NULL) ? zone : size;
  if (!spritesheet)
    {
      SDL_LogError(SPR_LCAT, IMG_GetError());
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

void	draw_sprite(t_texture *s, SDL_Rect *zone)
{
  if (!s)
    {
      SDL_LogError(SPR_LCAT, "draw_sprite: s is NULL");
      return ;
    }
  SDL_RenderCopy(get_renderer(), s->tex, NULL, zone);
  SDL_RenderPresent(get_renderer());
  SDL_LogDebug(SPR_LCAT, "Drawn sprite");
}

void		draw_sprite_raw(t_texture *s, SDL_Point *orig)
{
  if (!s)
    SDL_LogError(SPR_LCAT, "draw_sprite_raw: s is NULL");
  if (!orig)
    SDL_LogError(SPR_LCAT, "draw_sprite_raw: orig is NULL");
  if (!s || !orig)
    return ;
  draw_sprite(s, &(SDL_Rect){orig->x, orig->y, s->w, s->h});
}
