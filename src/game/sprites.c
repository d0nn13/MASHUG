/*
** sprites.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 01:03:17 2014 AHAMADA Samir
** Last update Sat May  3 15:47:52 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "graphic_handler.h"
#include "sprite_handler.h"
#include "sprites.h"

static t_texture	*Sprites[2];

void		load_sprites()
{
  const char* sheet = "media/gfx/sprites_sheet_alpha.png";

  Sprites[CABINET_SPR] = make_sprite(sheet, &(SDL_Rect){5, 993, 256, 224}, NULL);
  Sprites[TITLE_SPR] = make_sprite(sheet, &(SDL_Rect){17, 8, 588, 166},
				   &(SDL_Rect){0, 0, 420, 119});
  SDL_LogInfo(SPR_LCAT, "Sprites loaded.");
}

t_texture	*get_sprite(t_sprite s)
{
  return (Sprites[s]);
}

void		set_sprite(t_sprite s, t_texture *tex)
{
  Sprites[s] = tex;
}

void		free_sprites()
{
  t_sprite i;

  for (i = 0; i < NB_SPR; ++i)
    free_texture(Sprites[i]);
  SDL_LogInfo(SPR_LCAT, "Sprites destroyed.");
}
