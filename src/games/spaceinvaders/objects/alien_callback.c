/*
** alien_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
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
#include "alien.h"

#include "alien_callback.h"

static SDL_Rect	const	space_bounds = {141, 120, 486, 432};

void		spacealien_display(t_spacealien const *alien)
{
  static Uint8	s = 0;
  
  if (!ptr_chk(alien, "alien", APP_LCAT, "spacealien_display"))
    return ;
  draw_sprite(alien->sprite[s], &alien->rect);
  s = 0 ? 1 : 0;
}

void	spacealien_move(t_spacealien  *alien)
{
}

void	spacealien_fire()
{
}

void	spacealien_collide()
{
}

