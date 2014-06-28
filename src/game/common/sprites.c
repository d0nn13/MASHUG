/*
** sprites.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 01:03:17 2014 AHAMADA Samir
** Last update Sat Jun 28 18:05:50 2014 AHAMADA Samir
*/

#include "../../core/log.h"
#include "../../core/handlers.h"

#include "sprites.h"

static t_texture	*common_sprites[NB_SPR];

void		load_common_sprites()
{
  const char* sheet = "media/gfx/sprites_sheet_alpha.png";

  common_sprites[CABINET_SPR] = make_sprite(sheet,
					    &(SDL_Rect){5, 993, 256, 224}, NULL);
  common_sprites[TITLE_SPR] = make_sprite(sheet, &(SDL_Rect){17, 8, 588, 166},
					  &(SDL_Rect){0, 0, 420, 119});
  SDL_LogInfo(SPR_LCAT, "Sprites loaded");
}

t_texture	*get_common_sprite(t_common_sprite s)
{
  return (common_sprites[s]);
}

void		set_common_sprite(t_common_sprite s, t_texture *tex)
{
  common_sprites[s] = tex;
}

void			free_common_sprites()
{
  t_common_sprite	i;

  for (i = 0; i < NB_SPR; ++i)
    free_texture(common_sprites[i]);
  SDL_LogInfo(SPR_LCAT, "Sprites destroyed");
}
