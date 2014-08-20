/*
** sprites.h for MASHUG in
**
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
**
** Started on  Wed Jul 16 13:43:59 2014 Emmanuel Atse
** Last update Sat Sep  6 17:32:42 2014 ENNEBATI Yassine
*/

/**
 *	@file	sprites.h
 *	@brief	Space Invaders sprites initializer
 */

#ifndef	GAMES_SPACEINVADERS_SPRITES_H_
# define GAMES_SPACEINVADERS_SPRITES_H_

# include "../../core/graphics.h"

/**
 *	Spaceinvaders sprites names
 */
# define CABINET_SPR		"cabinet"
# define TITLE_SPR		"title"
# define NB_SPR			"nb"
# define OBJ_RESIZE_FACTOR	1

/**
 *	@brief	Load spaceinvaders sprite sheet
 */
Uint8			spacesprites_init();

/**
 *	@brief	Sprite sheet getter
 */
t_spritesheet const	*get_spacesprites();

/**
 *	@brief	Destroys spaceinvaders spritesheet
 */
void			spacesprites_destroy();

#endif		/* !GAMES_SPACEINVADERS_SPRITES_H_ */
