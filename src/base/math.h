/*
** math.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
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

# define MAX(a, b)		( ((a) > (b)) ? (a) : (b) )
# define MIN(a, b)		( ((a) < (b)) ? (a) : (b) )
# define T_LT(a, b, c, d)	( ((a) < (b)) ? (c) : (d) )
# define T_GT(a, b, c, d)	( ((a) > (b)) ? (c) : (d) )
# define T_EQ(a, b, c, d)	( ((a) == (b)) ? (c) : (d) )
# define IN_RANGE(v, a, b)	( (v) >= (a) && (v) <= (b) )
# define IN_XRANGE(v, a, b)	( (v) > (a) && (v) < (b) )
# define IS_BELOW(v, max)	( (v) <= (max) )
# define IS_ABOVE(v, min)	( (v) >= (min) )

/**
 *	Centering algorithm
 *	Returns an offset to have the dimension 'd'
 *	centered into the 'ref' dimension
 */
Uint32	ctr(Uint32 d, Uint32 ref);

#endif /* !BASE_MATH_H */
