/*
** spacespritesheet.c for spaceinvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Jul 29 00:12:24 2014 Samir Ahamada
** Last update Tue Jul 29 00:12:24 2014 Samir Ahamada
*/

#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/handlers.h"
#include "../common/sprites.h"

#include "spacespritesheet.h"

static t_spritesheet	*spacespritesheet;

/*
** TODO: Remove hard sprites definition when the xml parsing is done
*/
void			load_space_spritesheet()
{
  t_spritesheet		*ss;
  Uint8			sprite_count;

  spacespritesheet = make_spritesheet("media/gfx/sprites_sheet_alpha.png");
  sprite_count = 2;
  ss = spacespritesheet;
  ss->sprites = mem_alloc(sizeof(t_spriteholder *) * (sprite_count + 1));
  ss->sprites[sprite_count] = NULL;
  ss->sprites[0] = mem_alloc(sizeof(t_spriteholder));
  ss->sprites[0]->name = TITLE_SPR;
  ss->sprites[0]->rect = rect_factory(17, 8, 588, 166);
  ss->sprites[1] = mem_alloc(sizeof(t_spriteholder));
  ss->sprites[1]->name = CABINET_SPR;
  ss->sprites[1]->rect = rect_factory(5, 993, 256, 224);
}

t_spritesheet const	*get_space_spritesheet()
{
  return (spacespritesheet);
}

void			free_space_spritesheet()
{
  free_spritesheet(spacespritesheet);
}

