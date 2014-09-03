/*
** spacespritesheet.c for spaceinvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Jul 29 00:12:24 2014 Samir Ahamada
** Last update Wed Sep  3 14:59:05 2014 Emmanuel Atse
*/

#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/handlers.h"

#include "spacesprites.h"

static t_spritesheet	*spacespritesheet = NULL;

void			load_space_sprites()
{
  spacespritesheet = make_spritesheet("media/gfx/sprites_sheet_alpha.png",
				      "media/gfx/sprites_sheet_alpha.sprites");
}

t_spritesheet const	*get_space_sprites()
{
  return (spacespritesheet);
}

void			free_space_sprites()
{
  free_spritesheet(spacespritesheet);
  spacespritesheet = NULL;
}

