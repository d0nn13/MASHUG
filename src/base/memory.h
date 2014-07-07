/*
** memory.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu Jun 26 01:26:55 2014 AHAMADA Samir
** Last update Fri Jul  4 20:41:57 2014 AHAMADA Samir
*/

/**
 *	@file	base/memory.h
 *	@brief	Memory handling
 */

#ifndef	BASE_MEMORY_H
# define BASE_MEMORY_H

# include <stdlib.h>
# include <SDL_stdinc.h>


/**
 *	@brief	Allocates heap memory and increments allocation counter
 *
 *	@param	size The size of heap memory to allocate
 */
void	*mem_alloc(size_t size);

/**
 *	@brief	Frees allocated heap memory and decrements allocation counter
 *
 *	@param	ptr A pointer to the heap-allocated memory to free
 */
void	mem_free(void *ptr);

/**
 *	@brief	Returns the difference between the amount of allocations
 *		and the amount of frees
 *
 *	@return	The difference between the amount of allocations
 *		and the amount of frees as an integer
 */
Uint16	mem_get_nb_allocs();

#endif /* !BASE_MEMORY_H */
