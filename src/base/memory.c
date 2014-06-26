/*
** memory.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jun 26 01:31:07 2014 AHAMADA Samir
** Last update Thu Jun 26 18:02:11 2014 AHAMADA Samir
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
  void	*try;

  try = malloc(size);
  if (try)
    ++nb_allocs;
  else
    {
      printf("FATAL ERROR : Couldn't allocate heap memory (%d bytes)\n",
	     (Uint32)size);
      exit(EXIT_FAILURE);
    }
  return (try);
}

void	mem_free(void *ptr)
{
  if (!ptr)
    printf("FATAL ERROR : Tried to free NULL pointer\n");
  else
    {
      free(ptr);
      --nb_allocs;
    }
}

Uint16	get_nb_allocs()
{
  return (nb_allocs);
}
