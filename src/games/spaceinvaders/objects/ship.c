/*
** ship.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:54 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:56:17 2014 Emmanuel Atse
*/

#include "../../../base/memory.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../spacesprites.h"
#include "ship_callback.h"

#include "ship.h"

static t_spaceship	*ship = NULL;

void			spaceship_init()
{
  t_spriteholder const	*sprite = get_sprite(get_spacesprites(), "ship");

  ship = mem_alloc(1, sizeof(t_spaceship));
  ship->display = &spaceship_display;
  ship->move = &spaceship_move;
  ship->fire = &spaceship_fire;
  ship->sprite = sprite;
  ship->rect = rect_factory(350, 520, sprite->rect.w * OBJ_RESIZE_FACTOR,
			    sprite->rect.h * OBJ_RESIZE_FACTOR);
}

void			spaceship_destroy()
{
  mem_free(ship);
  ship = NULL;
}

t_spaceship	*get_spaceship()
{
  return (ship);
}
