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
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "alien_callback.h"

#include "alien.h"

#define NB_ALIENS	55

static t_singlelist	*aliens = NULL;

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

static void	position_update(Uint8 index, SDL_Rect *rect)
{
  if (!index || (index + 1) % 11)
    rect->x += 50;
  else
  {
    rect->x = 122;
    rect->y += 50;
  }
}

void			spacealiens_init()
{
  t_spacealien		*alien;
  t_singlelist		*node;
  static SDL_Rect	rect;
  Uint8			i;

  rect = rect_factory(122, 120, 0, 0);
  aliens = list_make_node();
  node = aliens;
  for (i = 0; i < NB_ALIENS; ++i)
  {
    alien = mem_alloc(1, sizeof(t_spacealien));
    alien->display = &spacealien_display;
    alien->move = &spacealien_move;
    alien->fire = &spacealien_fire;
    alien->collide = &spacealien_collide;
    sprite_select(i, alien->sprite);
    alien->rect = rect_factory(rect.x, rect.y,
			       alien->sprite[0]->rect.w * OBJ_RESIZE_FACTOR,
			       alien->sprite[0]->rect.h * OBJ_RESIZE_FACTOR);
    position_update(i, &rect);
    if (!i)
      node->data = alien;
    else
      list_push(alien, &node);
  }
}

void	spacealiens_destroy()
{
  t_singlelist	*node;

  for (node = aliens; node; node = node->next)
  {
    mem_free(node->data);
    node->data = NULL;
  }
  list_clear(&aliens);
  aliens = NULL;
}

t_singlelist	*get_spacealiens()
{
  return (aliens);
}
