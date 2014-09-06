/*
** context.h for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:39:02 2014 FOFANA Ibrahim
** Last update Fri Sep  5 15:51:31 2014 FOFANA Ibrahim
*/

/**
 *	@file	context.h
 *	@brief	SpaceInvaders game context (Lives, score)
 */

#ifndef GAME_SPACEINVADERS_CONTEXT_H_
# define GAME_SPACEINVADERS_CONTEXT_H_

#include <SDL2/SDL_stdinc.h>

/**
 *	@brief Spaceinvaders context structure definition
 */
typedef struct	s_spacecontext
{
  Uint8		score;
  Uint8		lives;
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

#endif /* !GAME_SPACEINVADERS_CONTEXT_H_ */
