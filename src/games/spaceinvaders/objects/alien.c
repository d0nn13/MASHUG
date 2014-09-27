/*
** alien.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:10:42 2014 ENNEBATI Yassine
** Last update Fri Sep 26 10:47:52 2014 Emmanuel Atse
*/

#include "../../../base/memory.h"
#include "../../../core/log.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "alien_callback.h"

#include "alien.h"


static void	specs_select(Uint8 index, t_spacealien * const alien)
{
  if (index < 2)
  {
    alien->sprite[0] = get_sprite(get_spacesprites(), "alien0a");
    alien->sprite[1] = get_sprite(get_spacesprites(), "alien0b");
    alien->score_gain = 30;
  }
  else if (index < 4)
  {
    alien->sprite[0] = get_sprite(get_spacesprites(), "alien1a");
    alien->sprite[1] = get_sprite(get_spacesprites(), "alien1b");
    alien->score_gain = 20;
  }
  else if (index < 5)
  {
    alien->sprite[0] = get_sprite(get_spacesprites(), "alien2a");
    alien->sprite[1] = get_sprite(get_spacesprites(), "alien2b");
    alien->score_gain = 10;
  }
}

static t_singlelist	*make_column(SDL_Rect *rect)
{
  t_singlelist		*column;
  t_singlelist		*node;
  t_spacealien		*alien;
  Uint8			i;

  column = list_make_node();
  node = column;
  for (i = 0; i < NB_ALIENS_ROW; ++i)
  {
    alien = mem_alloc(1, sizeof(t_spacealien));
    alien->collide = &spacealien_collide;
    specs_select(i, alien);
    alien->rect = rect_factory(rect->x, rect->y,
			       alien->sprite[0]->rect.w * OBJ_RESIZE_FACTOR,
			       alien->sprite[0]->rect.h * OBJ_RESIZE_FACTOR);
    *rect = rect_factory(rect->x, rect->y, alien->rect.w, alien->rect.h);
    if (!i)
      node->data = (t_spacealien*)alien;
    else
      list_push((t_spacealien*)alien, &node);
    rect->y -= rect->h + ALIEN_PAD;
  }
  return (column);
}

t_spacealiens		*spacealiens_init()
{
  t_spacealiens		*aliens;
  SDL_Rect		rect;
  Uint8			i;

  aliens = mem_alloc(1, sizeof(t_spacealiens));
  memset(aliens->columns, 0, sizeof(aliens->columns));
  aliens->display = &spacealien_display;
  aliens->move = &spacealien_move;
  aliens->fire = &spacealien_fire;
  aliens->direction = 1;
  rect = rect_factory(190, 334, 0, 0);
  for (i = 0; i < NB_ALIENS_COL; ++i)
  {
    aliens->columns[i] = make_column(&rect);
    rect.y = 334;
    rect.x += rect.w + ALIEN_PAD;
  }
  return (aliens);
}

void		spacealiens_destroy(t_spacealiens **aliens)
{
  t_singlelist	*node;
  Uint8		i;

  if (!ptr_chk(*aliens, "aliens", APP_LCAT, "spacealiens_destroy"))
    return ;
  for (i = 0; i < NB_ALIENS_COL; ++i)
  {
    if (!(*aliens)->columns[i])
      continue ;
    for (node = (*aliens)->columns[i]; node; node = node->next)
    {
      if (node->data)
	mem_free(node->data);
      node->data = NULL;
    }
    list_clear(&(*aliens)->columns[i]);
  }
  mem_free(*aliens);
  *aliens = NULL;
}
