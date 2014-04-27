/*
** math.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Apr 17 23:03:39 2014 AHAMADA Samir
** Last update Sun Apr 27 17:49:21 2014 AHAMADA Samir
*/

#ifndef MATH_H
#define MATH_H

#include <SDL2/SDL_stdinc.h>

#define max(a, b)	(((a) > (b)) ? (a) : (b))
#define min(a, b)	(((a) < (b)) ? (a) : (b))

/**
 *	Centering algorithm
 *	Returns an offset to have the dimension 'd'
 *	centered into the 'ref' dimension
 */
Uint32	ctr(Uint32 d, Uint32 ref);

#endif /* !MATH_H */
