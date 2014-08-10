/*
** ship_callback.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:07 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:07:46 2014 ENNEBATI Yassine
*/

/**
 *	@file	ship_callback.h
 *	@brief	Spaceinvaders ship definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECT_SHIP_CALLBACK_H_
# define GAMES_SPACEINVADERS_OBJECT_SHIP_CALLBACK_H_

# include "ship.h"

/**
 *	@brief	Spaceinvaders ship display callback
 */
void	spaceship_display(t_spaceship const *ship);

/**
 *	@brief	Spaceinvaders ship move callback
 */
void	spaceship_move();

/**
 *	@brief	Spaceinvaders ship fire callback
 */
void	spaceship_fire();

/**
 *	@brief	Spaceinvaders ship collide callback
 */
void	spaceship_collide();

#endif /* !GAMES_SPACEINVADERS_OBJECT_SHIP_CALLBACK_H_ */

