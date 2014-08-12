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

void	spaceblock_display(t_spaceblock const *block)
{
  Uint8	i;

  if (!ptr_chk(block, "block object", APP_LCAT, "spaceblock_display"))
    return ;
  for (i = 0; i < 4; ++i)
    draw_sprite(block[i].sprite[0], &block[i].rect);
}

void	spaceblock_collide()
{
  
}

