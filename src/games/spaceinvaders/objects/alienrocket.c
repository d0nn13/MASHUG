/*
** alienrocket.c for mashug in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Fri Sep 26 01:54:10 2014 Emmanuel Atse
** Last update Fri Sep 26 02:30:16 2014 Emmanuel Atse
*/

#include "../../../base/memory.h"
#include "../../../core/log.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "alienrocket_callback.h"
#include "rocket.h"

t_spacerocket		*spacealienrocket_init()
{
  t_spacerocket		*rocket;
  t_spriteholder const	*sprite = get_sprite(get_spacesprites(), "rocket0");

  rocket = mem_alloc(1, sizeof(t_spacerocket));
  rocket->display = &spacealienrocket_display;
  rocket->collide = &spacealienrocket_collide;
  rocket->sprite = sprite;
  rocket->rect = rect_factory(0, 0, sprite->rect.w * OBJ_RESIZE_FACTOR,
			      sprite->rect.h * OBJ_RESIZE_FACTOR);
  rocket->state = IDLE;
  return (rocket);
}
