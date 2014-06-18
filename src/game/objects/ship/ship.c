/*
** ship.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Jun 15 01:01:07 2014 AHAMADA Samir
** Last update Sun Jun 15 20:12:19 2014 AHAMADA Samir
*/

#include "../sprite_handler.h"
#include "ship.h"

t_object	*make_ship(void)
{
  t_object	*ship;
  SDL_Texture	*tex;
  const char	*sheet = SPRITESHEET;

  ship = malloc(sizeof(t_object));
  ship->pos = {0, 0};
  tex = make_sprite(sheet, &(SDL_Rect){355, 1163, 104, 64}, NULL);
  set_sprite(SHIP_SPR, tex);
 
  return (ship);
}

