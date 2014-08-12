/*
** ship.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:54 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:01:54 2014 ENNEBATI Yassine
*/

#include "../../../base/memory.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../spacespritesheet.h"
#include "ship_callback.h"

#include "ship.h"

static t_spaceship	*ship;

void			spaceship_init()
{
  t_spriteholder const	*sprite = get_sprite(get_space_spritesheet(), "ship");

  ship = mem_alloc(sizeof(t_spaceship));
  ship->display = &spaceship_display;
  ship->move = &spaceship_move;
  ship->fire = &spaceship_fire;
  ship->collide = &spaceship_collide;
  ship->sprite = sprite;
  ship->rect = rect_factory(350, 520, sprite->rect.w * 2, sprite->rect.h * 2);
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
