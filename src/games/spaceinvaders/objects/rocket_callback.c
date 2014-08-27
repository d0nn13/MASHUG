/*
** rocket_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
*/

#include "../../../base/list.h"
#include "../../../core/log.h"
#include "../../../core/input.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../spacespritesheet.h"
#include "../spacecore.h"
#include "rocket.h"
#include "alien.h"
#include "block.h"

#include "rocket_callback.h"

static void		display_impact(t_spacerocket const *rocket)
{
  t_spriteholder const	*spr = get_sprite(get_space_spritesheet(), "impact0");
  SDL_Rect		impact;

  impact = rect_factory(rocket->rect.x - spr->rect.w / 2 + rocket->rect.w / 2,
			rocket->rect.y, spr->rect.w, spr->rect.h);
  draw_sprite(spr, &impact);
}

void			spacerocket_display(t_spacerocket *rocket)
{
  Uint8 const		step = 8;

  if (!ptr_chk(rocket, "rocket", APP_LCAT, "spacerocket_display"))
    return ;
  if (rocket->state == FIRED)
  {
    draw_sprite(rocket->sprite, &rocket->rect);
    rocket->rect.y -= step;
    if (rocket->rect.y + rocket->rect.h < get_spacebounds()->y)
    {
      rocket->rect = rect_factory(0, 0, rocket->rect.w, rocket->rect.h);
      rocket->state = IDLE;
    }
  }
  else if (rocket->state == COLLIDED)
  {
    display_impact(rocket);
    rocket->rect = rect_factory(0, 0, rocket->rect.w, rocket->rect.h);
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
  node = get_spacealiens();
  while (node)
  {
    if (SDL_HasIntersection(&rocket->rect, &((t_spacealien *)
					     node->data)->rect))
      rocket->state = COLLIDED;
    node = node->next;
  }
  node = get_spaceblocks();
  while (node)
  {
    if (SDL_HasIntersection(&rocket->rect, &((t_spaceblock *)
					     node->data)->rect))
      rocket->state = COLLIDED;
    node = node->next;
  }
}
