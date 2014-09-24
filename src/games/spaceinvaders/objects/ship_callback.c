/*
** ship_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
** Last update Tue Aug 12 22:35:24 2014 ENNEBATI Yassine
*/

#include "../../../core/log.h"
#include "../../../core/input.h"
#include "../../../core/handlers.h"
#include "../core.h"
#include "ship.h"
#include "rocket.h"

#include "ship_callback.h"

void	spaceship_display(t_spaceship const *ship)
{
  if (!ptr_chk(ship, "ship", APP_LCAT, "spaceship_display"))
    return ;
  draw_sprite(ship->sprite, &ship->rect);
}

void	       	spaceship_move(t_spaceship  *ship)
{
  Uint8 const  	vel = 2;

  input_update();
  if (get_input(LEFT_INP)->state)
    ship->rect.x = (ship->rect.x - vel >= get_spacebounds()->x + 10) ?
      ship->rect.x - vel : ship->rect.x;
  if (get_input(RIGHT_INP)->state)
    ship->rect.x = (ship->rect.x + vel <= get_spacebounds()->x +
		    get_spacebounds()->w - ship->rect.w - 10) ?
      ship->rect.x + vel : ship->rect.x;
}

void	spaceship_fire(t_spaceship const *ship, t_spacerocket *rocket)
{
  rocket->rect.x = ship->rect.x + ship->rect.w / 2 - rocket->rect.w / 2;
  rocket->rect.y = ship->rect.y - rocket->rect.h;
  rocket->state = FIRED;
}
