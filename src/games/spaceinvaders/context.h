/*
** context.h for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:39:02 2014 FOFANA Ibrahim
** Last update Fri Sep 26 10:59:42 2014 Emmanuel Atse
*/

/**
 *	@file	context.h
 *	@brief	SpaceInvaders game context (Lives, score)
 */

#ifndef GAME_SPACEINVADERS_CONTEXT_H_
# define GAME_SPACEINVADERS_CONTEXT_H_

# include <SDL2/SDL_stdinc.h>

/**
 *	@brief Spaceinvaders context structure definition
 */
typedef struct	s_spacecontext
{
  Uint32	score;
  Uint8		lives;
  Uint8		wave;
  float		level;
}		t_spacecontext;

/**
 *	@brief Initializes Space Invaders context
 */
Uint8	spacecontext_init();

/**
 *	@brief Destroys Space Invaders context
 */
void	spacecontext_destroy();

/**
 *	@brief spacecontext getter
 */
t_spacecontext	*get_spacecontext();

/**
 *	@brief Increase spacecontext life when the score reach a 1500 multiple
 */
void    spacecontext_increase_life_process();

#endif /* !GAME_SPACEINVADERS_CONTEXT_H_ */
