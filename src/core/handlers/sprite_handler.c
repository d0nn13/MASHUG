/*
** sprite_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Tue Jun 24 23:01:43 2014 AHAMADA Samir
*/

/**
 *	@file	sprite_handler.c
 *	@brief	Sprite handling interface
 */

#include <SDL2/SDL_image.h>
#include "../log.h"
#include "../renderer.h"

#include "../handlers.h"

t_texture	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size)
{
  SDL_Surface	*sprite;
  SDL_Surface	*spritesheet;
  t_texture	*out;
  SDL_Rect	*s;

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
  SDL_RenderCopy(get_renderer(), s->tex, NULL, zone);
  SDL_RenderPresent(get_renderer());
  SDL_LogDebug(SPR_LCAT, "Drawn sprite");
}

void		draw_sprite_raw(t_texture *s, SDL_Point *orig)
{
  if (!orig)
    {
      SDL_LogError(SPR_LCAT, "Passed NULL origin point");
      return ;
    }
  draw_sprite(s, &(SDL_Rect){orig->x, orig->y,
	s->w, s->h});
}
