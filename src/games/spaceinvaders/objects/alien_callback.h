/*
** alien_callback.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects/alien
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:11:46 2014 ENNEBATI Yassine
** Last update Sun Aug 10 02:47:22 2014 ENNEBATI Yassine
*/

/**
 *	@file	alien_callback.h
 *	@brief	Spaceinvaders alien definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECTS_ALIEN_CALLBACK_H_
# define GAMES_SPACEINVADERS_OBJECTS_ALIEN_CALLBACK_H_

# include "alien.h"

/**
 *	@brief	Spaceinvaders alien display callback
 */
void	spacealien_display(t_spacealiens *aliens);

/**
 *	@brief	Spaceinvaders alien move callback
 */
void	spacealien_move(t_spacealiens *aliens);

/**
 *	@brief	Spaceinvaders alien fire callback
 */
void	spacealien_fire(t_spacealiens *aliens, t_spacerocket *rocket);

/**
 *	@brief	Spaceinvaders alien collide callback
 */
void	spacealien_collide();

#endif /* !GAMES_SPACEINVADERS_OBJECTS_ALIEN_CALLBACK_H_ */

