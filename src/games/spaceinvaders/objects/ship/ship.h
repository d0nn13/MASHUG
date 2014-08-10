/*
** ship.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects/ship
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:10:35 2014 ENNEBATI Yassine
** Last update Sun Aug 10 02:34:35 2014 ENNEBATI Yassine
*/

/**
 *	@file	ship.h
 *	@brief	Space Invaders ship definition
 */

#ifndef	GAMES_SPACEINVADERS_SHIP_H_
# define GAMES_SPACEINVADERS_SHIP_H_

# include <SDL2/SDL.h>
# include "../../../../core/graphics.h"

/**
 *	@brief	Spaceinvaders ship structure definition
 */
typedef struct		s_spaceship
{
  void			(*display)(struct s_spaceship const *ship);
  void			(*move)(struct s_spaceship *ship);
  void			(*fire)();
  void			(*collide)();
  t_spriteholder const	*sprite;
  SDL_Rect 		rect;
}			t_spaceship;

/**
 *	@brief	Initializes Space Invaders ship
 */
void	space_init_ship();

/**
 *	@brief	Ship getter
 */
t_spaceship	*get_spaceship();



#endif /* !GAMES_SPACEINVADERS_SHIP_H_ */
