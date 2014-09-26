/*
** alienrocket_callback.h for mashug in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Fri Sep 26 01:55:23 2014 Emmanuel Atse
** Last update Fri Sep 26 02:43:49 2014 Emmanuel Atse
*/

/**
 *	@file	alienrocket_callback.h
 *	@brief	Spaceinvaders alien's rocket definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECT_ALIENROCKET_CALLBACK_H_
# define GAMES_SPACEINVADERS_OBJECT_ALIENROCKET_CALLBACK_H_

# include "rocket.h"

/**
 *	@brief	Spaceinvaders alienrocket display callback
 */
void	spacealienrocket_display(t_spacerocket *rocket, int index);

/**
 *	@brief	Spaceinvaders alienrocket collide callback
 */
void	spacealienrocket_collide(t_spacerocket *rocket, int index);

#endif /* !GAMES_SPACEINVADERS_OBJECT_ALIENROCKET_CALLBACK_H_ */
