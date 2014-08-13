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

static t_spaceblock	*block = NULL;
static char		*block_spr_names[NB_SPACE_BLOCK_SPR] =
{
  "block0",
  "block1"
};

void			spaceblock_init()
{
  Uint8			b;
  Uint8			s;
  SDL_Rect		rect;

  rect.x = 140;
  block = mem_alloc(BLOCK_NB * sizeof(t_spaceblock));
  for (b = 0; b < BLOCK_NB; ++b)
  {
    block[b].display = &spaceblock_display;
    block[b].collide = &spaceblock_collide;
    for (s = 0; s < NB_SPACE_BLOCK_SPR; ++s)
      block[b].sprite[s] = get_sprite(get_space_spritesheet(), block_spr_names[s]);
    rect = rect_factory(rect.x, 400,
			block[b].sprite[0]->rect.w * OBJ_RESIZE_FACTOR,
			block[b].sprite[0]->rect.h * OBJ_RESIZE_FACTOR); 
    block[b].rect = rect;
    rect.x += 132; 
  }
}

void	spaceblock_destroy()
{
  mem_free(block);
  block = NULL;
}

t_spaceblock	*get_spaceblocks()
{
  return (block);
}  


