/*
** alienrocket_callback.c for mashug in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Fri Sep 26 02:02:39 2014 Emmanuel Atse
** Last update Fri Sep 26 03:22:48 2014 Emmanuel Atse
*/

#include <SDL2/SDL.h>

#include "../core.h"
#include "../sprites.h"
#include "../../../core/log.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../context.h"

#include "alienrocket_callback.h"

#define IMPACT_PERSIST	7

static Uint8			display_impact(t_spacerocket const *rocket,
					       int index)
{
  t_spriteholder const * const	spr = get_sprite(get_spacesprites(), "impact0");
  SDL_Rect			impact[NB_ALIENS_ROCKETS];
  static Uint8			persist[NB_ALIENS_ROCKETS] =
    {IMPACT_PERSIST, IMPACT_PERSIST, IMPACT_PERSIST, IMPACT_PERSIST,
     IMPACT_PERSIST};

  impact[index] = rect_factory(rocket->rect.x - spr->rect.w / 2 +
			       rocket->rect.w / 2,
			       rocket->rect.y, spr->rect.w, spr->rect.h);
  if (persist[index]--)
  {
    draw_sprite(spr, &impact[index]);
    return (1);
  }
  persist[index] = IMPACT_PERSIST;
  return (0);
}

void	spacealienrocket_display(t_spacerocket *rocket, int index)
{
  float const		vel = 1;

  if (!ptr_chk(rocket, "rocket", APP_LCAT, "alienspacerocket_display"))
    return ;
  if (rocket->state == FIRED)
  {
    draw_sprite_ex(rocket->sprite, &rocket->rect, 0, SDL_FLIP_VERTICAL);
    rocket->rect.y += vel;
    if (rocket->rect.y + rocket->rect.h >
	get_spacebounds()->h + get_spacebounds()->y)
    {
      rocket->rect = rect_factory(0, 0, rocket->rect.w, rocket->rect.h);
      rocket->state = IDLE;
    }
  }
  else if (rocket->state == COLLIDED)
  {
    if (!display_impact(rocket, index))
    rocket->state = IDLE;
  }
  else
    rocket->rect = rect_factory(0, 0, rocket->rect.w, rocket->rect.h);
}

void	spacealienrocket_collide(t_spacerocket *rocket, int index)
{
  t_spaceship		*ship;
  t_singlelist const    *node;

  (void)index;
  if (rocket->state != FIRED)
    return ;
  ship = get_spaceobjects()->ship;
  if (SDL_HasIntersection(&rocket->rect, &ship->rect))
    {
      rocket->state = COLLIDED;
      --get_spacecontext()->lives;
      return ;
    }
  for (node = get_spaceobjects()->blocks; node; node = node->next)
    if (SDL_HasIntersection(&rocket->rect, &((t_spaceblock *)
					     node->data)->rect))
      rocket->state = COLLIDED;
}
