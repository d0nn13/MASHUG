/*
** ship_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects/ship
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:11:56 2014 ENNEBATI Yassine
** Last update Sun Aug 10 02:14:04 2014 ENNEBATI Yassine
*/

#include "../../../../core/log.h"
#include "../../../../core/input.h"
#include "../../../../core/handlers.h"
#include "ship.h"

#include "ship_callback.h"

static SDL_Rect	const	space_bounds = {141, 120, 486, 432};

void	spaceship_display(t_spaceship const *ship)
{
  if (!ptr_chk(ship, "ship", APP_LCAT, "spaceship_display"))
    return ;
  draw_sprite(ship->sprite, &ship->rect);
}

void	       	spaceship_move(t_spaceship  *ship)
{
  Uint8 const  	step = 10;

  input_update();
  if (get_input(LEFT_INP)->state)
    ship->rect.x = (ship->rect.x - step >= space_bounds.x) ?
      ship->rect.x - step : ship->rect.x;
  if (get_input(RIGHT_INP)->state)
    ship->rect.x = (ship->rect.x + step <= space_bounds.x +
		    space_bounds.w - ship->rect.w) ? ship->rect.x + step : ship->rect.x;
}

void	spaceship_fire()
{
  
}

void	spaceship_collide()
{
  
}

