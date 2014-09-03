/*
** spacespritesheet.h for MASHUG in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Wed Jul 16 13:43:59 2014 Emmanuel Atse
** Last update Wed Sep  3 14:53:35 2014 Emmanuel Atse
*/

#ifndef	GAMES_SPACESPRITESHEET_H_
# define GAMES_SPACESPRITESHEET_H_

# include "../../core/graphics.h"

/**
 *	Spaceinvaders sprites names
 */
# define CABINET_SPR		"cabinet"
# define TITLE_SPR		"title"
# define NB_SPR			"nb"
# define OBJ_RESIZE_FACTOR	1.5

/**
 *	@brief	Load spaceinvaders sprite sheet
 */
void			load_space_sprites();

/**
 *	@brief	Sprite sheet getter
 */
t_spritesheet const	*get_space_sprites();

/**
 *	@brief	Destroys spaceinvaders spritesheet
 */
void			free_space_sprites();

#endif		/* !GAMES_SPACESPRITESHEET_H_ */
