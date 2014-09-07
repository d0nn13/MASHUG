/*
** ufo_callback.h for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 15:15:04 2014 FOFANA Ibrahim
** Last update Sun Sep  7 15:51:03 2014 FOFANA Ibrahim
*/

/**
 *	@file	ufo_callback.h
 *	@brief	Spaceinvaders ufo definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECTS_UFO_CALLBACK_H__
# define GAMES_SPACEINVADERS_OBJECTS_UFO_CALLBACK_H__

# include "ufo.h"

/**
 *	@brief	Spaceinvaders ufo display callback
 */
void	spaceufo_display(t_spaceufo *ufo);

/**
 *	@brief	Spaceinvaders ufo move callback
 */
void	spaceufo_move();

/**
 *	@brief	Spaceinvaders ufo collide callback
 */
void	spaceufo_collide();

#endif /* !GAMES_SPACEINVADERS_OBJECTS_UFO_CALLBACK_H__ */
