/*
** ufo_callback.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug/src/games/spaceinvaders/objects
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 15:14:45 2014 FOFANA Ibrahim
** Last update Mon Sep  8 17:58:31 2014 FOFANA Ibrahim
*/

#include "../../../core/handlers.h"
#include "../core.h"

#include "ufo_callback.h"

#define	UFO_VEL	1
#define UFO_MAX_X (get_spacebounds()->x + get_spacebounds()->w)
#define UFO_MIN_X (get_spacebounds()->x)

void	spaceufo_display(t_spaceufo const *ufo)
{
  if (ufo->direction != UFO_NONE)
    draw_sprite(ufo->sprite, &ufo->rect);
}

void	spaceufo_move(t_spaceufo *ufo)
{
  if (ufo->direction == UFO_NONE)
    return ;

  if (ufo->rect.x > UFO_MAX_X + (ufo->rect.w / 2))
    ufo->direction = UFO_LEFT;
  if (ufo->rect.x <  UFO_MIN_X - (ufo->rect.w * 1.5))
    ufo->direction = UFO_RIGHT;

  if (ufo->direction == UFO_RIGHT)
    ufo->rect.x += UFO_VEL;
  else if (ufo->direction == UFO_LEFT)
    ufo->rect.x -= UFO_VEL;
}
