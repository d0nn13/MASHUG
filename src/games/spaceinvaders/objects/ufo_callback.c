/*
** ufo_callback.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug/src/games/spaceinvaders/objects
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 15:14:45 2014 FOFANA Ibrahim
** Last update Mon Sep  8 19:08:49 2014 FOFANA Ibrahim
*/

#include "../../../core/handlers.h"
#include "../core.h"

#include "ufo_callback.h"

#include <stdlib.h>

#define	UFO_VEL 1
#define	UFO_MAX_X (get_spacebounds()->x + get_spacebounds()->w + 100)
#define	UFO_MIN_X (get_spacebounds()->x - 100)
#define	UFO_ELAPSED_TIME (40000 + rand() % 40000)

static	void	spaceufo_appear(t_spaceufo *ufo);

static	Uint32	ti = 0;

void		spaceufo_display(t_spaceufo const *ufo)
{
  if (ufo->direction != UFO_NONE)
    draw_sprite(ufo->sprite, &ufo->rect);
}

void		spaceufo_move(t_spaceufo *ufo)
{
  if (ufo->direction == UFO_NONE)
    spaceufo_appear(ufo);

  if (ufo->rect.x > UFO_MAX_X)
    ufo->direction = UFO_NONE;
  if (ufo->rect.x <  UFO_MIN_X)
    ufo->direction = UFO_NONE;

  if (ufo->direction == UFO_RIGHT)
    ufo->rect.x += UFO_VEL;
  else if (ufo->direction == UFO_LEFT)
    ufo->rect.x -= UFO_VEL;
}

static	void	spaceufo_appear(t_spaceufo *ufo)
{
  Uint32	to;

  to = SDL_GetTicks();

  if ((to - ti) > UFO_ELAPSED_TIME)
  {
    ti = SDL_GetTicks();
    if (rand() % 2)
    {
      ufo->direction = UFO_RIGHT;
      ufo->rect.x = UFO_MIN_X;
    }
    else
    {
      ufo->direction = UFO_LEFT;
      ufo->rect.x = UFO_MAX_X;
    }
  }
}
