/*
** rocket.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:44 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:08:06 2014 ENNEBATI Yassine
*/

/**
 *	@file	rocket.h
 *	@brief	Space Invaders rocket definition
 */

#ifndef	GAMES_SPACEINVADERS_OBJECT_ROCKET_H_
# define GAMES_SPACEINVADERS_OBJECT_ROCKET_H_

# include <SDL2/SDL.h>
# include "../../../core/graphics.h"

typedef enum
{
  IDLE = 0,
  FIRED,
  COLLIDED
}		t_spacerocket_state;

/**
 *	@brief	Spaceinvaders rocket structure definition
 */
typedef struct		s_spacerocket
{
  void			(*display)(struct s_spacerocket *rocket);
  void			(*collide)(struct s_spacerocket *rocket);
  t_spriteholder const	*sprite;
  SDL_Rect 		rect;
  t_spacerocket_state	state;
}			t_spacerocket;

/**
 *	@brief	Initializes Space Invaders rocket
 */
t_spacerocket	*spacerocket_init();

/**
 *	@brief	Destroys Space Invaders rocket
 */
void	spacerocket_destroy(t_spacerocket **rocket);

#endif /* !GAMES_SPACEINVADERS_OBJECT_ROCKET_H_ */
