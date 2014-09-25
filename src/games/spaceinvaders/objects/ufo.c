/*
** ufo.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug/src/games/spaceinvaders/objects
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 12:10:35 2014 FOFANA Ibrahim
** Last update Thu Sep 25 20:55:13 2014 FOFANA Ibrahim
*/

#include "../../../base/memory.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../../../core/log.h"
#include "../sprites.h"
#include "../core.h"
#include "ufo_callback.h"

#include "ufo.h"

t_spaceufo		*spaceufo_init()
{
  t_spaceufo		*ufo;
  t_spriteholder const	*sprite = get_sprite(get_spacesprites(), "ufo");

  ufo = mem_alloc(1, sizeof(t_spaceufo));
  ufo->display = &spaceufo_display;
  ufo->move = &spaceufo_move;
  ufo->sprite = sprite;
  ufo->rect = rect_factory(get_spacebounds()->x - (get_spacebounds()->w * 1.5),
			   get_spacebounds()->y + (get_spacebounds()->h / 8),
			   sprite->rect.w * OBJ_RESIZE_FACTOR,
			   sprite->rect.h * OBJ_RESIZE_FACTOR);
  ufo->score_gain = 0;
  ufo->direction = UFO_NONE;
  return (ufo);
}

void	spaceufo_destroy(t_spaceufo **ufo)
{
  if (!ptr_chk(*ufo, "ufo", APP_LCAT, "spaceufo_destroy"))
    return ;
  mem_free(*ufo);
  *ufo = NULL;
}
