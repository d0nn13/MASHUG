/*
** rocket_callback.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Sun Aug 10 04:02:07 2014 ENNEBATI Yassine
** Last update Sat Sep  6 17:29:49 2014 ENNEBATI Yassine
*/

/**
 *	@file	rocket_callback.h
 *	@brief	Spaceinvaders rocket definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECT_ROCKET_CALLBACK_H_
# define GAMES_SPACEINVADERS_OBJECT_ROCKET_CALLBACK_H_

# include "rocket.h"

/**
 *	@brief	Spaceinvaders rocket display callback
 */
void	spacerocket_display(t_spacerocket *rocket);

/**
 *	@brief	Spaceinvaders rocket collide callback
 */
void	spacerocket_collide(t_spacerocket *rocket);

#endif /* !GAMES_SPACEINVADERS_OBJECT_ROCKET_CALLBACK_H_ */
