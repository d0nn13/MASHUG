/*
** memory.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/base
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Mar 26 01:07:45 2014 AHAMADA Samir
** Last update Wed Mar 26 01:07:47 2014 AHAMADA Samir
*/

#ifndef MEMORY_H
# define MEMORY_H

#include <stdlib.h>

/*
 * Allocates (size) bytes of memory on the heap and returns a pointer
 * pointing to it
 */
void	*mem_alloc(size_t size);

/*
 * Frees the heap allocated bytes pointed by (ptr)
 */
void	mem_free(void *ptr);

/*
 * Checks if there is a memory leak
 */
void	mem_leakchk();

/*
 * Returns the amount of allocations
 */
int	mem_count();

/*
 * Print memory related error messages
 */
int	mem_error(int err);

#endif /* !MEMORY_H */
