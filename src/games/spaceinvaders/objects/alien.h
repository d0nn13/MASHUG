/*
** alien.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Fri Apr 25 22:30:46 2014 AHAMADA Samir
** Last update Sat Sep  6 17:29:04 2014 ENNEBATI Yassine
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

/**
 *	@brief	Spaceinvaders alien structure definition
 */
typedef struct		s_spacealien
{
  void			(*display)(t_singlelist *alien);
  void			(*move)(struct s_spacealien *alien);
  void			(*fire)(void *rocket);	/* TODO: change type to rocket */
  void			(*collide)();
  t_spriteholder const	*sprite[2];
  SDL_Rect 		rect;
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
