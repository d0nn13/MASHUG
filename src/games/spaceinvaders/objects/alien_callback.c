/*
** alien_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:17 2014 ENNEBATI Yassine
** Last update Tue Aug 12 22:30:17 2014 ENNEBATI Yassine
*/

#include "../../../base/list.h"
#include "../../../core/log.h"
#include "../../../core/input.h"
#include "../../../core/handlers.h"
#include "../core.h"
#include "alien.h"

#include "alien_callback.h"

void		spacealien_display(t_singlelist	*aliens)
{
  t_singlelist	*node;
  Uint32	t;
  
  t = SDL_GetTicks() / 1000;
  for (node = aliens; node; node = node->next)
    draw_sprite(ALIEN_CAST(node)->sprite[t % 2], &ALIEN_CAST(node)->rect);
}

void		spacealien_move(t_singlelist *aliens)
{
  static Sint8	dir = 1;
  static Uint32	old_t = 0;
  t_singlelist	*node;
  t_spacealien	*last_alien;
  
  if (SDL_GetTicks() - old_t < 1000)
    return ;
  for (node = aliens; node->next; node = node->next)
    ;
  last_alien = ALIEN_CAST(node);
  if ((dir < 0 && (ALIEN_CAST(aliens)->rect.x - ALIEN_CAST(aliens)->rect.w <=
		   get_spacebounds()->x)) ||
      (dir > 0 && (last_alien->rect.x + 2 * last_alien->rect.w >=
		   get_spacebounds()->x + get_spacebounds()->w)))
  {
    dir = -dir;
    for (node = aliens; node; node = node->next)
      ALIEN_CAST(node)->rect.y += ALIEN_CAST(node)->rect.h / 2 + ALIEN_PAD;
  }
  else
    for (node = aliens; node; node = node->next)
      ALIEN_CAST(node)->rect.x += (ALIEN_CAST(node)->rect.w + ALIEN_PAD) * dir;
  old_t = SDL_GetTicks();
}

void		spacealien_fire(t_singlelist *aliens)
{
}

void	spacealien_collide()
{
}
