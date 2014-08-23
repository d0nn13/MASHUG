/*
** block_callback.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
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

#include "block_callback.h"

void		spaceblock_display(t_singlelist *blocks)
{
  t_singlelist	*node;

  if (!ptr_chk(blocks, "block list", APP_LCAT, "spaceblock_display"))
    return ;
  for (node = blocks; node; node = node->next)
    draw_sprite(((t_spaceblock *)node->data)->sprite[0],
		&((t_spaceblock *)node->data)->rect);
}

void	spaceblock_collide()
{
  
}

