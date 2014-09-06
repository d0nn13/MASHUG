/*
** block.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:54 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:57:58 2014 Emmanuel Atse
*/

#include "../../../base/memory.h"
#include "../../../core/log.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../sprites.h"
#include "block_callback.h"

#define BLOCK_NB	4

static char		*block_spr_names[NB_SPACE_BLOCK_SPR] =
{
  "block0",
  "block1"
};

t_singlelist		*spaceblocks_init()
{
  t_singlelist		*blocks;
  t_spaceblock		*block;
  t_singlelist		*node;
  SDL_Rect		rect;
  Uint8			b;
  Uint8			s;

  rect.x = 140;
  blocks = list_make_node();
  node = blocks;
  for (b = 0; b < BLOCK_NB; ++b)
  {
    block = mem_alloc(1, sizeof(t_spaceblock));
    block->display = &spaceblock_display;
    block->collide = &spaceblock_collide;
    for (s = 0; s < NB_SPACE_BLOCK_SPR; ++s)
      block->sprite[s] = get_sprite(get_spacesprites(), block_spr_names[s]);
    rect = rect_factory(rect.x, 400,
			block->sprite[0]->rect.w * OBJ_RESIZE_FACTOR,
			block->sprite[0]->rect.h * OBJ_RESIZE_FACTOR);
    block->rect = rect;
    rect.x += 132;
    if (!b)
      node->data = block;
    else
      list_push(block, &node);
  }
  return (blocks);
}

void	spaceblocks_destroy(t_singlelist **blocks)
{
  t_singlelist	*node;

  if (!ptr_chk(*blocks, "blocks", APP_LCAT, "spaceblocks_destroy"))
    return ;
  for (node = *blocks; node; node = node->next)
  {
    mem_free(node->data);
    node->data = NULL;
  }
  list_clear(blocks);
}
