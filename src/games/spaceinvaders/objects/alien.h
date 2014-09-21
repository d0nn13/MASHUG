/*
** alien.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Fri Apr 25 22:30:46 2014 AHAMADA Samir
** Last update Sun Sep 21 19:51:38 2014 FOFANA Ibrahim
*/

/**
 *	@file	alien.h
 *	@brief	Space Invaders alien definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECTS_ALIEN_H_
# define GAMES_SPACEINVADERS_OBJECTS_ALIEN_H_

# include <SDL2/SDL.h>
# include "../../../base/list.h"
# include "../../../core/graphics.h"

#define ALIEN_CAST(n)	((t_spacealien *)n->data)

/**
 *	@brief	Spaceinvaders alien structure definition
 */
typedef struct		s_spacealien
{
  void			(*display)(t_singlelist *alien);
  void			(*move)(t_singlelist *alien);
  void			(*fire)(void *rocket);	/* TODO: change type to rocket */
  void			(*collide)();
  t_spriteholder const	*sprite[2];
  SDL_Rect 		rect;
  Uint8			score_gain;
}			t_spacealien;

/**
 *	@brief	Initializes Space Invaders alien
 */
t_singlelist		*spacealiens_init();

/**
 *	@brief	Destroys Space Invaders alien
 */
void	spacealiens_destroy(t_singlelist **aliens);

#endif /* !GAMES_SPACEINVADERS_OBJECTS_ALIEN_H_ */
