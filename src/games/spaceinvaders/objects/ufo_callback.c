/*
** ufo_callback.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug/src/games/spaceinvaders/objects
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 15:14:45 2014 FOFANA Ibrahim
** Last update Sun Sep  7 16:54:55 2014 FOFANA Ibrahim
*/

#include "../../../core/handlers.h"
#include "../core.h"

#include "ufo_callback.h"

#define	UFO_VEL	1

void	spaceufo_display(t_spaceufo const *ufo)
{
    draw_sprite(ufo->sprite, &ufo->rect);
}

void	spaceufo_move(t_spaceufo *ufo)
{
  if (ufo->direction == UFO_NONE)
    return ;
  if (ufo->rect.x + ufo->rect.w > get_spacebounds()->x + get_spacebounds()->w)
    ufo->direction = UFO_LEFT;
  if (ufo->rect.x < get_spacebounds()->x)
    ufo->direction = UFO_RIGHT;
  if (ufo->direction == UFO_RIGHT)
    ufo->rect.x += UFO_VEL;
  else if (ufo->direction == UFO_LEFT)
    ufo->rect.x -= UFO_VEL;
}
