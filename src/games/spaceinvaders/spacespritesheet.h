/*
** spacespritesheet.h for MASHUG in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Wed Jul 16 13:43:59 2014 Emmanuel Atse
** Last update Wed Jul 16 13:51:22 2014 Emmanuel Atse
*/

#ifndef		GAMES_SPACEINVADERS_SPRITESHEET_H_
# define	GAMES_SPACEINVADERS_SPRITESHEET_H_

#include		"../../core/graphics.h"

void			load_space_spritesheet();
t_spritesheet const	*get_space_spritesheet();
void			free_space_spritesheet();

#endif		/* !GAMES_SPACEINVADERS_SPRITESHEET_H_ */
