/*
** rocket_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
** Last update Sun Sep  7 17:04:59 2014 FOFANA Ibrahim
*/

#include "../../../base/list.h"
#include "../../../core/log.h"
#include "../../../core/input.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "../core.h"
#include "rocket.h"
#include "alien.h"
#include "block.h"

#include "rocket_callback.h"

#define IMPACT_PERSIST	7

static Uint8			display_impact(t_spacerocket const *rocket)
{
  t_spriteholder const * const	spr = get_sprite(get_spacesprites(), "impact0");
  SDL_Rect			impact;
  static Uint8			persist = IMPACT_PERSIST;

  impact = rect_factory(rocket->rect.x - spr->rect.w / 2 + rocket->rect.w / 2,
			rocket->rect.y, spr->rect.w, spr->rect.h);
  if (persist--)
  {
    draw_sprite(spr, &impact);
    return (1);
  }
  persist = IMPACT_PERSIST;
  return (0);
}

void			spacerocket_display(t_spacerocket *rocket)
{
  Uint8 const		vel = 2;

  if (!ptr_chk(rocket, "rocket", APP_LCAT, "spacerocket_display"))
    return ;
  if (rocket->state == FIRED)
  {
    draw_sprite(rocket->sprite, &rocket->rect);
    rocket->rect.y -= vel;
    if (rocket->rect.y + rocket->rect.h < get_spacebounds()->y)
    {
      rocket->rect = rect_factory(0, 0, rocket->rect.w, rocket->rect.h);
      rocket->state = IDLE;
    }
  }
  else if (rocket->state == COLLIDED)
  {
    if (!display_impact(rocket))
    rocket->state = IDLE;
  }
  else
    rocket->rect = rect_factory(0, 0, rocket->rect.w, rocket->rect.h);
}

void			spacerocket_collide(t_spacerocket *rocket)
{
  t_singlelist const    *node;

  if (rocket->state != FIRED)
    return ;
  for (node = get_spaceobjects()->aliens; node; node = node->next)
    if (SDL_HasIntersection(&rocket->rect, &((t_spacealien *)
					     node->data)->rect))
      rocket->state = COLLIDED;
  for (node = get_spaceobjects()->blocks; node; node = node->next)
    if (SDL_HasIntersection(&rocket->rect, &((t_spaceblock *)
					     node->data)->rect))
      rocket->state = COLLIDED;
  if (SDL_HasIntersection(&rocket->rect, &get_spaceobjects()->ufo->rect))
      rocket->state = COLLIDED;
}
