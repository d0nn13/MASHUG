/*
** block->c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:54 2014 ENNEBATI Yassine
** Last update Tue Aug 12 21:56:37 2014 ENNEBATI Yassine
*/

#include "../../../base/memory.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../spacespritesheet.h"
#include "block_callback.h"

#define BLOCK_NB	4

static t_singlelist	*blocks = NULL;
static char		*block_spr_names[NB_SPACE_BLOCK_SPR] =
{
  "block0",
  "block1"
};

void			spaceblock_init()
{
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
    block = mem_alloc(sizeof(t_spaceblock));
    block->display = &spaceblock_display;
    block->collide = &spaceblock_collide;
    for (s = 0; s < NB_SPACE_BLOCK_SPR; ++s)
      block->sprite[s] = get_sprite(get_space_spritesheet(), block_spr_names[s]);
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
}

void	spaceblock_destroy()
{
  t_singlelist	*node;

  for (node = blocks; node; node = node->next)
  {
    mem_free(node->data);
    node->data = NULL;
  }
  list_clear(&blocks);
  blocks = NULL;
}

t_singlelist	*get_spaceblocks()
{
  return (blocks);
}  


