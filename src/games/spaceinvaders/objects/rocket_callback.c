/*
** rocket_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
*/

#include "../../../core/log.h"
#include "../../../core/input.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "rocket.h"

#include "rocket_callback.h"

void	spacerocket_display(t_spacerocket *rocket)
{
  Uint8 const  	step = 8;

  if (!ptr_chk(rocket, "rocket", APP_LCAT, "spacerocket_display"))
    return ;
  if (rocket->fired)
  {
    if (rocket->rect.y + rocket->rect.h < 120) /* 120 = space_bounds UP */
      rocket->fired = 0;
    draw_sprite(rocket->sprite, &rocket->rect);
    rocket->rect.y -= step;
  }
}

void	spacerocket_collide()
{

}

