/*
** alien.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Fri Apr 25 22:30:46 2014 AHAMADA Samir
** Last update Fri Sep 26 10:26:19 2014 Emmanuel Atse
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
# include "rocket.h"

#define ALIEN_PAD	10
#define NB_ALIENS_COL	11
#define NB_ALIENS_ROW	5
#define ALIEN_CAST(n)	((t_spacealien *)n->data)

/**
 *	@brief	Spaceinvaders alien structure definition
 */
typedef struct		s_spacealien
{
  void			(*collide)(t_singlelist *, t_singlelist **);
  t_spriteholder const	*sprite[2];
  SDL_Rect 		rect;
  Uint8			score_gain;
}			t_spacealien;

/**
 *	@brief	Spaceinvaders alien formation structure definition
 */
typedef struct		s_spacealiens
{
  t_singlelist		*columns[NB_ALIENS_COL + 1];
  void			(*display)(struct s_spacealiens *aliens);
  void			(*move)(struct s_spacealiens *aliens);
  void			(*fire)(struct s_spacealiens *aliens,
				t_spacerocket **rocket);
  void			(*update_rect)(struct s_spacealiens *aliens);
  Sint8			direction;
}			t_spacealiens;

/**
 *	@brief	Initializes Space Invaders alien
 */
t_spacealiens		*spacealiens_init();

/**
 *	@brief	Destroys Space Invaders alien
 */
void	spacealiens_destroy(t_spacealiens **aliens);

#endif /* !GAMES_SPACEINVADERS_OBJECTS_ALIEN_H_ */
