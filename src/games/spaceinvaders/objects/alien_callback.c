/*
** alien_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
** Last update Fri Sep 26 11:09:38 2014 Emmanuel Atse
*/

#include "../../../core/helpers.h"
#include "../../../base/list.h"
#include "../../../base/memory.h"
#include "../../../core/log.h"
#include "../../../core/input.h"
#include "../../../core/handlers.h"
#include "../context.h"
#include "../core.h"
#include "alien.h"

#include "alien_callback.h"

static void	get_range(t_spacealiens *aliens, SDL_Rect *range)
{
  Uint8		i;

  for (i = 0; i < NB_ALIENS_COL &&
	 (!aliens->columns[i] || !aliens->columns[i]->data); ++i)
    ;
  if (!aliens->columns[i] || !aliens->columns[i]->data)
    return ;
  range->x = ALIEN_CAST(aliens->columns[i])->rect.x;
  range->w = ALIEN_CAST(aliens->columns[i])->rect.w;
  for (i = NB_ALIENS_COL - 1; !aliens->columns[i] ||
       !aliens->columns[i]->data; --i)
    ;
  range->y = ALIEN_CAST(aliens->columns[i])->rect.x;
}

void		spacealien_display(t_spacealiens *aliens)
{
  t_singlelist	*node;
  Uint8		i;
  Uint32	t;

  t = SDL_GetTicks() / 1000;
  for (i = 0; i < NB_ALIENS_COL; ++i)
    if (!aliens->columns[i])
      continue;
    else
      for (node = aliens->columns[i]; node; node = node->next)
	draw_sprite(ALIEN_CAST(node)->sprite[t % 2], &ALIEN_CAST(node)->rect);
}

void		spacealien_move(t_spacealiens *aliens)
{
  static Uint32	old_t = 0;
  t_singlelist	*node;
  SDL_Rect	range;
  Uint8		i;

  if (SDL_GetTicks() - old_t < 1000 / get_spacecontext()->level)
    return ;
  get_range(aliens, &range);
  if ((aliens->direction < 0 && (range.x - range.w <= get_spacebounds()->x)) ||
      (aliens->direction > 0 && (range.y + 2 * range.w >= get_spacebounds()->x
  				 + get_spacebounds()->w)))
  {
    aliens->direction = -aliens->direction;
    for (i = 0; i < NB_ALIENS_COL; ++i)
      if (aliens->columns[i])
	for (node = aliens->columns[i]; node; node = node->next)
	  ALIEN_CAST(node)->rect.y += ALIEN_CAST(node)->rect.h / 2 + ALIEN_PAD;
  }
  else
    for (i = 0; i < NB_ALIENS_COL; ++i)
      if (aliens->columns[i])
	for (node = aliens->columns[i]; node; node = node->next)
	  ALIEN_CAST(node)->rect.x += (ALIEN_CAST(node)->rect.w) *
	    aliens->direction;
  old_t = SDL_GetTicks();
}

void		spacealien_fire(t_spacealiens *aliens, t_spacerocket **rocket)
{
  static Uint32	old_t = 0;
  Uint8		i;
  Uint8		j;

  if (!ptr_chk(aliens, "aliens", APP_LCAT, "spacealien_fire"))
    return ;
  if (SDL_GetTicks() - old_t < (Uint32)(((rand() % 9500) + 1500) /
					get_spacecontext()->level))
    return ;
  i = rand() % NB_ALIENS_COL;
  for (j = 0; j < 3 && !aliens->columns[i]; ++j)
    i = rand() % NB_ALIENS_COL;
  if (!aliens->columns[i] || !aliens->columns[i]->data)
    return ;
  for (j = 0; j < NB_ALIENS_ROCKETS; ++j)
    if (rocket[j]->state == IDLE)
      break;
  if (j >= NB_ALIENS_ROCKETS)
    return ;
  rocket[j]->rect = rect_factory(ALIEN_CAST(aliens->columns[i])->rect.x +
				 ALIEN_CAST(aliens->columns[i])->rect.w / 2,
				 ALIEN_CAST(aliens->columns[i])->rect.y,
				 rocket[j]->rect.w,
				 rocket[j]->rect.h);
  rocket[j]->state = FIRED;
  old_t = SDL_GetTicks();
}

void	spacealien_collide(t_singlelist *alien_node, t_singlelist **root)
{
  get_spacecontext()->score += ALIEN_CAST(alien_node)->score_gain;
  get_spacecontext()->level  += 0.01;
  mem_free(ALIEN_CAST(alien_node));
  list_pop(alien_node, root);
}
