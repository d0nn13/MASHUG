/*
** core.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:32 2014 ENNEBATI Yassine
** Last update Fri Sep 26 03:03:29 2014 Emmanuel Atse
*/

/**
 *	@file	core.h
 *	@brief	Space Invaders Game!!
 */

#ifndef GAMES_SPACEINVADERS_CORE_H_
# define GAMES_SPACEINVADERS_CORE_H_

# include "objects/ship.h"
# include "objects/rocket.h"
# include "objects/alien.h"
# include "objects/block.h"
# include "objects/ufo.h"

# define NB_ALIENS_ROCKETS 5

typedef struct	s_spaceobjects
{
  t_spaceship	*ship;
  t_spacerocket	*rocket;
  t_spacealiens	*aliens;
  t_spacerocket *alien_rockets[NB_ALIENS_ROCKETS];
  t_singlelist	*blocks;
  t_spaceufo	*ufo;
}		t_spaceobjects;

/**
 *	@brief	Initialises object instances
 */
void	spacecore_init();

/**
 *	@brief	Destroys object instances
 */
void	spacecore_destroy();

/**
 *	@brief	Main loop
 */
void	space_loop();

/**
 *	@brief	Space objects getter
 */
t_spaceobjects	*get_spaceobjects();

/**
 *	@brief	Space bounds getter
 */
SDL_Rect const	*get_spacebounds();

#endif /* !GAMES_SPACEINVADERS_CORE_H_ */
