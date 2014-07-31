/*
** commonspritesheet.h for common in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jul 31 14:19:17 2014 Samir Ahamada
** Last update Thu Jul 31 14:19:17 2014 Samir Ahamada
*/

#ifndef	GAMES_COMMONSPRITESHEET_H_
# define GAMES_COMMONSPRITESHEET_H_

#include "../../core/graphics.h"

/**
 *	Common sprites names
 */

/**
 *	@brief	Load common sprite sheet
 */
void			load_common_spritesheet();

/** @brief	Common spritesheet getter
 */
t_spritesheet const	*get_common_spritesheet();

/**
 *	@brief	Destroys common spritesheet
 */
void			free_common_spritesheet();

#endif		/* !GAMES_COMMONSPRITESHEET_H_ */
