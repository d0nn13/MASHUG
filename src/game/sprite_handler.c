/*
** sprite_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Sun Apr 27 23:35:15 2014 AHAMADA Samir
*/

#include <SDL2/SDL_image.h>
#include "../core/log.h"
#include "../core/renderer.h"
#include "gamedefs.h"
#include "sprite_handler.h"

SDL_Surface	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size)
{
  SDL_Surface	*sprite;
  SDL_Surface	*spritesheet;
  SDL_Rect	*s;

  sprite = NULL;
  spritesheet = IMG_Load_RW(SDL_RWFromFile(file, "rb"), 1);
  s = (size == NULL) ? zone : size;
  if (!spritesheet)
    SDL_LogError(SPR_LCAT, IMG_GetError());
  else
    {
      SDL_SetSurfaceBlendMode(spritesheet, SDL_BLENDMODE_NONE);
      sprite = SDL_CreateRGBSurface(0, s->w, s->h, 32,
				    RMASK, GMASK, BMASK, AMASK);
      if (!sprite)
	SDL_LogError(SPR_LCAT, SDL_GetError());
      else
	SDL_BlitScaled(spritesheet, zone, sprite, NULL);
      SDL_FreeSurface(spritesheet);
    }
  return (sprite);
}

void	draw_sprite(t_sprite s, SDL_Rect *zone)
{
  set_texture(SDL_CreateTextureFromSurface(get_renderer(), get_sprite(s)));
  SDL_SetTextureBlendMode(get_texture(), SDL_BLENDMODE_BLEND);
  SDL_RenderCopy(get_renderer(), get_texture(), NULL, zone);
  SDL_RenderPresent(get_renderer());
  SDL_LogInfo(SPR_LCAT, "Drawn sprite %d", s);
}

void		draw_sprite_raw(t_sprite s, SDL_Point *orig)
{
  SDL_Rect	zone;

  if (!orig)
    {
      SDL_LogError(SPR_LCAT, "Passed NULL origin point");
      return ;
    }
  zone = (SDL_Rect){orig->x, orig->y, get_sprite(s)->w, get_sprite(s)->h};
  draw_sprite(s, &zone);
}
