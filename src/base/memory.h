/*
** memory.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jun 26 01:26:55 2014 AHAMADA Samir
** Last update Sat Jun 28 16:33:27 2014 AHAMADA Samir
*/

/*
**	@file	base/memory.h
**	@brief	Memory handling
*/

#ifndef	BASE_MEMORY_H
# define BASE_MEMORY_H

# include <stdlib.h>
# include <SDL_stdinc.h>

void	*mem_alloc(size_t size);
void	mem_free(void *ptr);
Uint16	mem_get_nb_allocs();

#endif /* !BASE_MEMORY_H */
