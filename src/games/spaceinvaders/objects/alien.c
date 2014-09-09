/*
** alien.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:10:42 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:56:56 2014 Emmanuel Atse
*/

#include "../../../base/memory.h"
#include "../../../core/log.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "alien_callback.h"

#include "alien.h"

#define NB_ALIENS	55

static void	sprite_select(Uint8 index, t_spriteholder const **sh)
{
  if (index < 11)
  {
    sh[0] = get_sprite(get_spacesprites(), "alien0a");
    sh[1] = get_sprite(get_spacesprites(), "alien0b");
  }
  else if (index < 33)
  {
    sh[0] = get_sprite(get_spacesprites(), "alien1a");
    sh[1] = get_sprite(get_spacesprites(), "alien1b");
  }
  else if (index < 55)
  {
    sh[0] = get_sprite(get_spacesprites(), "alien2a");
    sh[1] = get_sprite(get_spacesprites(), "alien2b");
  }
}

static t_spacealien	*make_alien(SDL_Rect const *rect, Uint8 const *i)
{
  t_spacealien		*alien;

  alien = mem_alloc(1, sizeof(t_spacealien));
  alien->display = &spacealien_display;
  alien->move = &spacealien_move;
  alien->fire = &spacealien_fire;
  alien->collide = &spacealien_collide;
  sprite_select(*i, alien->sprite);
  alien->rect = rect_factory(rect->x, rect->y,
			     alien->sprite[0]->rect.w * OBJ_RESIZE_FACTOR,
			     alien->sprite[0]->rect.h * OBJ_RESIZE_FACTOR);
  return (alien);
}

t_singlelist		*spacealiens_init()
{
  t_singlelist		*aliens;
  t_singlelist		*node;
  SDL_Rect		rect;
  Uint8			i;

  rect = rect_factory(122, 120, 0, 0);
  aliens = list_make_node();
  node = aliens;
  for (i = 0; i < NB_ALIENS; ++i)
  {
    if (!i)
      node->data = make_alien(&rect, &i);
    else
      list_push(make_alien(&rect, &i), &node);
    if (!i || (i + 1) % 11)
      rect.x += 50;
    else
    {
      rect.x = 122;
      rect.y += 50;
    }
  }
  return (aliens);
}

void		spacealiens_destroy(t_singlelist **aliens)
{
  t_singlelist	*node;

  if (!ptr_chk(*aliens, "aliens", APP_LCAT, "spacealiens_destroy"))
    return ;
  for (node = *aliens; node; node = node->next)
  {
    mem_free(node->data);
    node->data = NULL;
  }
  list_clear(aliens);
}
