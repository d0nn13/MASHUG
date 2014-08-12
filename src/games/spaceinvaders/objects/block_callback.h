/*
** block_callback.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:02:07 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:07:46 2014 ENNEBATI Yassine
*/

/**
 *	@file	block_callback.h
 *	@brief	Spaceinvaders block definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECT_BLOCK_CALLBACK_H_
# define GAMES_SPACEINVADERS_OBJECT_BLOCK_CALLBACK_H_

# include "block.h"

/**
 *	@brief	Spaceinvaders block display callback
 */
void	spaceblock_display(t_spaceblock const *block);

/**
 *	@brief	Spaceinvaders block collide callback
 */
void	spaceblock_collide();

#endif /* !GAMES_SPACEINVADERS_OBJECT_BLOCK_CALLBACK_H_ */

