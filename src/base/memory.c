/*
** memory.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu Jun 26 01:31:07 2014 AHAMADA Samir
** Last update Mon Jul 14 01:57:49 2014 ENNEBATI Yassine
*/

/**
 *	@file	base/memory.c
 *	@brief	Memory handling
 */

#include <stdlib.h>
#include <SDL2/SDL_stdinc.h>

#include "memory.h"

static Uint16	nb_allocs = 0;

void	*mem_alloc(size_t size)
{
  void	*try;

  try = malloc(size);
  if (try)
    ++nb_allocs;
  else
  {
    fprintf(stderr, "FATAL ERROR : Couldn't allocate heap memory (%d bytes)\n",
	    (Uint32)size);
    exit(EXIT_FAILURE);
  }
  return (try);
}

void	mem_free(void *ptr)
{
  if (!ptr)
    fprintf(stderr, "FATAL ERROR : Tried to free NULL pointer\n");
  else
  {
    free(ptr);
    --nb_allocs;
  }
}

Uint16	mem_get_nb_allocs()
{
  return (nb_allocs);
}
