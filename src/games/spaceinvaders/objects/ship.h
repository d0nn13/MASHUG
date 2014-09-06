/*
** ship.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:44 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:08:06 2014 ENNEBATI Yassine
*/

/**
 *	@file	ship.h
 *	@brief	Space Invaders ship definition
 */

#ifndef	GAMES_SPACEINVADERS_OBJECT_SHIP_H_
# define GAMES_SPACEINVADERS_OBJECT_SHIP_H_

# include <SDL2/SDL.h>
# include "../../../core/graphics.h"
# include "rocket.h"

/**
 *	@brief	Spaceinvaders ship structure definition
 */
typedef struct		s_spaceship
{
  void			(*display)(struct s_spaceship const *ship);
  void			(*move)(struct s_spaceship *ship);
  void			(*fire)(struct s_spaceship const *ship, t_spacerocket *rocket);
  t_spriteholder const	*sprite;
  SDL_Rect 		rect;
}			t_spaceship;

/**
 *	@brief	Initializes Space Invaders ship
 */
t_spaceship	*spaceship_init();

/**
 *	@brief	Destroys Space Invaders ship
 */
void	spaceship_destroy(t_spaceship **ship);

#endif /* !GAMES_SPACEINVADERS_OBJECT_SHIP_H_ */
