/*
** ufo.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug/src/games/spaceinvaders/objects
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 12:10:35 2014 FOFANA Ibrahim
** Last update Sun Sep  7 15:48:54 2014 FOFANA Ibrahim
*/

#include "ufo.h"
#include "ufo_callback.h"
#include "../../../base/memory.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../../../core/log.h"
#include "../sprites.h"

t_spaceufo	*spaceufo_init()
{
  t_spaceufo	*ufo;
  t_spriteholder const *sprite = get_sprite(get_spacesprites(), "ufo");

  ufo = mem_alloc(1, sizeof(t_spaceufo));
  ufo->display = &spaceufo_display;
  ufo->move = &spaceufo_move;
  ufo->sprite = sprite;
  ufo->rect = rect_factory(350, 520, sprite->rect.w * OBJ_RESIZE_FACTOR,
			   sprite->rect.h * OBJ_RESIZE_FACTOR);
  return (ufo);
}

void	spaceufo_destroy(t_spaceufo *ufo)
{
  if (!ptr_chk(ufo, "ufo", APP_LCAT, "ufo_destroy"))
    return ;
  mem_free(ufo);
  ufo = NULL;
}
