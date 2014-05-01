/*
** gamecore.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 16:03:00 2014 AHAMADA Samir
** Last update Wed Apr 30 01:34:05 2014 AHAMADA Samir
*/

#include "../base/math.h"
#include "../core/log.h"
#include "../core/window.h"
#include "sprite_handler.h"
#include "font_handler.h"
#include "sound_handler.h"
#include "gamecore.h"

Sint32		init_game()
{
  SDL_Surface	*spr;

  load_sprites();
  load_fonts();
  load_sounds();
  draw_sprite(CABINET_SPR, NULL);
  spr = get_sprite(TITLE_SPR);
  draw_sprite_raw(TITLE_SPR, &(SDL_Point){ctr(spr->w, WIN_WIDTH), 112});
  return (0);
}

void	destroy_game()
{
  free_sounds();
  free_fonts();
  free_sprites();
}
