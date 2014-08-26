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
#include "../spacecore.h"
#include "ship.h"
#include "rocket.h"

#include "ship_callback.h"

void	spaceship_display(t_spaceship const *ship)
{
  if (!ptr_chk(ship, "ship", APP_LCAT, "spaceship_display"))
    return ;
  draw_sprite(ship->sprite, &ship->rect);
}

void	       	spaceship_move(t_spaceship *ship)
{
  Uint8 const  	step = 5;

  input_update();
  if (get_input(LEFT_INP)->state)
    ship->rect.x -= step;
  if (get_input(RIGHT_INP)->state)
    ship->rect.x += step;
}

void	spaceship_fire(t_spaceship const *ship, t_spacerocket *rocket)
{
  rocket->rect.x = ship->rect.x + ship->rect.w / 2 - rocket->rect.w / 2;
  rocket->rect.y = ship->rect.y - rocket->rect.h;
  rocket->state = FIRED;
}

void	spaceship_collide(t_spaceship *ship)
{
  if (ship->rect.x < get_spacebounds()->x)
    ship->rect.x = get_spacebounds()->x;
  if (ship->rect.x + ship->rect.w > get_spacebounds()->w + get_spacebounds()->w)
    ship->rect.x = get_spacebounds()->x + get_spacebounds()->w - ship->rect.w;
}

