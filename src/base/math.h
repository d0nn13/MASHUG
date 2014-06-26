/*
** math.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu Apr 17 23:03:39 2014 AHAMADA Samir
** Last update Thu Jun 26 17:11:09 2014 AHAMADA Samir
*/

#ifndef BASE_MATH_H
# define BASE_MATH_H

# include <SDL2/SDL_stdinc.h>

# define max(a, b)	(((a) > (b)) ? (a) : (b))
# define min(a, b)	(((a) < (b)) ? (a) : (b))

/**
 *	Centering algorithm
 *	Returns an offset to have the dimension 'd'
 *	centered into the 'ref' dimension
 */
Uint32	ctr(Uint32 d, Uint32 ref);

#endif /* !BASE_MATH_H */
