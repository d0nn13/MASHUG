/*
** memory.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jun 26 01:31:07 2014 AHAMADA Samir
** Last update Thu Jun 26 01:45:16 2014 AHAMADA Samir
*/

/*
**	@file	base/memory.c
**	@brief	Memory handling
*/

#include <stdlib.h>
#include <SDL2/SDL_stdinc.h>

#include "memory.h"

static Uint16	nb_allocs = 0;

void	*mem_alloc(size_t size)
{
  ++nb_allocs;
  return (malloc(size));
}

void	mem_free(void *ptr)
{
  --nb_allocs;
  free(ptr);
}

Uint16	get_nb_allocs()
{
  return (nb_allocs);
}
