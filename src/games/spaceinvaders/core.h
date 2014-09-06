/*
** core.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:32 2014 ENNEBATI Yassine
** Last update Sat Sep  6 17:15:54 2014 ENNEBATI Yassine
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

typedef struct	s_spaceobjects
{
  t_spaceship	*ship;
  t_spacerocket	*rocket;
  t_singlelist	*aliens;
  t_singlelist	*blocks;
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