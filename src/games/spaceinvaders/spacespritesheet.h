/*
** spacespritesheet.h for MASHUG in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Wed Jul 16 13:43:59 2014 Emmanuel Atse
** Last update Wed Jul 16 13:51:22 2014 Emmanuel Atse
*/

#ifndef	GAMES_SPACESPRITESHEET_H_
# define GAMES_SPACESPRITESHEET_H_

#include "../../core/graphics.h"

/**
 *	Spaceinvaders sprites names
 */
#define CABINET_SPR	"cabinet"
#define TITLE_SPR	"title"
#define NB_SPR		"nb"

/**
 *	@brief	Load spaceinvaders sprite sheet
 */
void			load_space_spritesheet();

/**
 *	@brief	Sprite sheet getter
 */
t_spritesheet const	*get_space_spritesheet();

/**
 *	@brief	Destroys spaceinvaders spritesheet
 */
void			free_space_spritesheet();

#endif		/* !GAMES_SPACESPRITESHEET_H_ */
