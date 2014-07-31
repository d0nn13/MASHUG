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

static t_spritesheet	*spacespritesheet = NULL;

void			load_space_spritesheet()
{
  t_spritesheet		*ss;
  Uint8			sprite_count;

  spacespritesheet = make_spritesheet("media/gfx/sprites_sheet_alpha.png");
  sprite_count = xml_parse("media/gfx/sprites_sheet_alpha.sprites",
			   SHEET_XML, NULL);
  ss = spacespritesheet;
  ss->sprites = mem_alloc(sizeof(t_spriteholder *) * (sprite_count + 1));
  if (!ptr_chk(ss->sprites, "sprites", SPR_LCAT, "load_space_spritesheet"))
    return ;
  xml_parse("media/gfx/sprites_sheet_alpha.sprites", SHEET_XML, ss->sprites);
}

t_spritesheet const	*get_space_spritesheet()
{
  return (spacespritesheet);
}

void			free_space_spritesheet()
{
  free_spritesheet(spacespritesheet);
}

