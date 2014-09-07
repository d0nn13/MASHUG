/*
** rocket.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:54 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:55:50 2014 Emmanuel Atse
*/

#include "../../../base/memory.h"
#include "../../../core/log.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "rocket_callback.h"

#include "rocket.h"


t_spacerocket		*spacerocket_init()
{
  t_spacerocket		*rocket;
  t_spriteholder const	*sprite = get_sprite(get_spacesprites(), "rocket0");

  rocket = mem_alloc(1, sizeof(t_spacerocket));
  rocket->display = &spacerocket_display;
  rocket->collide = &spacerocket_collide;
  rocket->sprite = sprite;
  rocket->rect = rect_factory(0, 0, sprite->rect.w * OBJ_RESIZE_FACTOR,
			      sprite->rect.h * OBJ_RESIZE_FACTOR);
  rocket->state = IDLE;
  return (rocket);
}

void	spacerocket_destroy(t_spacerocket **rocket)
{
  if (!ptr_chk(*rocket, "rocket", APP_LCAT, "spacerocket_destroy"))
    return ;
  mem_free(*rocket);
  *rocket = NULL;
}
