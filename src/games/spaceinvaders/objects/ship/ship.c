/*
** ship.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects/ship
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:10:42 2014 ENNEBATI Yassine
** Last update Sun Aug 10 02:24:01 2014 ENNEBATI Yassine
*/

#include "../../../../core/handlers.h"
#include "../../../../core/helpers.h"
#include "../../spacespritesheet.h"
#include "ship_callback.h"

#include "ship.h"

static t_spaceship	ship;

void			space_init_ship()
{
  t_spriteholder const	*sprite = get_sprite(get_space_spritesheet(), "ship");

  ship.display = &spaceship_display;
  ship.move = &spaceship_move;
  ship.fire = NULL;
  ship.collide = NULL;
  ship.sprite = sprite;
  ship.rect = rect_factory(350, 520, sprite->rect.w * 2, sprite->rect.h * 2);
}

t_spaceship	*get_spaceship()
{
  return (&ship);
}  


