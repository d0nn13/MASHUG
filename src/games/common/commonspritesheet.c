/*
** commonspritesheet.c for common in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jul 31 14:20:04 2014 Samir Ahamada
** Last update Thu Jul 31 14:20:04 2014 Samir Ahamada
*/

#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/handlers.h"

#include "commonspritesheet.h"

static t_spritesheet	*commonspritesheet = NULL;

void			load_common_spritesheet()
{
}

t_spritesheet const	*get_common_spritesheet()
{
  return (commonspritesheet);
}

void			free_common_spritesheet()
{
  free_spritesheet(commonspritesheet);
}

