/*
** sprites.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 01:03:17 2014 AHAMADA Samir
** Last update Sun Apr 27 18:29:36 2014 AHAMADA Samir
*/

#include <SDL2/SDL_image.h>
#include "../core/log.h"
#include "sprite_handler.h"
#include "sprites.h"

static SDL_Surface	*Sprites[2];

SDL_Surface	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size)
{
  SDL_Surface	*sprite;
  SDL_Surface	*spritesheet;
  SDL_Rect	*s;

  sprite = NULL;
  spritesheet = IMG_Load_RW(SDL_RWFromFile(file, "rb"), 1);
  s = (size == NULL) ? zone : size;
  if (!spritesheet)
    SDL_LogError(RDR_LCAT, IMG_GetError());
  else
    {
      SDL_SetSurfaceBlendMode(spritesheet, SDL_BLENDMODE_NONE);
      sprite = SDL_CreateRGBSurface(0, s->w, s->h, 32,
				    RMASK, GMASK, BMASK, AMASK);
      if (!sprite)
	SDL_LogError(RDR_LCAT, SDL_GetError());
      else
	SDL_BlitScaled(spritesheet, zone, sprite, NULL);
      SDL_FreeSurface(spritesheet);
    }
  return (sprite);
}

void		load_sprites()
{
  const char* sheet = "media/gfx/sprites_sheet_alpha.png";

  Sprites[CABINET_SPR] = make_sprite(sheet, &(SDL_Rect){5, 993, 256, 224}, NULL);
  Sprites[TITLE_SPR] = make_sprite(sheet, &(SDL_Rect){17, 8, 588, 166},
				   &(SDL_Rect){0, 0, 420, 119});
  SDL_LogInfo(RDR_LCAT, "Sprites loaded.");
}

SDL_Surface	*get_sprite(t_sprite s)
{
  return (Sprites[s]);
}

void		set_sprite(t_sprite s, SDL_Surface *sur)
{
  Sprites[s] = sur;
}

void		free_sprites()
{
  t_sprite i;

  for (i = 0; i < LAST_SPR; ++i)
    free(Sprites[i]);
  SDL_LogInfo(RDR_LCAT, "Sprites destroyed.");
}
