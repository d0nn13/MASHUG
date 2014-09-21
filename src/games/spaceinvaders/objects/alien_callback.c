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
    draw_sprite(((t_spacealien *)node->data)->sprite[t % 2],
		&((t_spacealien *)node->data)->rect);
}

void		spacealien_move(t_singlelist *aliens)
{
  static Uint32	old_t = 0;
  t_singlelist	*node;
  t_spacealien	*alien;
  Uint32	t;
  Uint8		col;
  
  t = SDL_GetTicks();
  if (t - old_t < 1000)
    return ;
  node = aliens;
  col = 0;
  while (node)
  {
    alien = (t_spacealien *)node->data;
    alien->rect.x += alien->rect.w * alien->direction;
    if (!SDL_HasIntersection(&alien->rect, get_spacebounds()))
      col = 1;
    node = node->next;
  }
  node = aliens;
  if (col)
    while (node)
    {
      alien = (t_spacealien *)node->data;
      alien->direction = -alien->direction;
      alien->rect.x += alien->rect.w * alien->direction;
      alien->rect.y += alien->rect.h;
      node = node->next;
    }
  old_t = t;
}

void	spacealien_fire()
{
}

void	spacealien_collide()
{
}
