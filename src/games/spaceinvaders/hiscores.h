/*
** hiscores.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:13 2014 ENNEBATI Yassine
** Last update Wed Sep 24 11:53:55 2014 FOFANA Ibrahim
*/

/**
 *	@file	hiscores.h
 *	@brief	Hi-Scores mode for space invaders game
 */

#ifndef GAMES_SPACEINVADERS_HISCORES_H_
# define GAMES_SPACEINVADERS_HISCORES_H_

#include "../../core/handlers.h"

/**
 *	Load HiScores
 */
Uint8	load_hiscores(t_hiscores *hiscores);

/**
 *	Save HiScores to system
 */
Uint8	save_spacehiscores(t_hiscoreholder entry);

/**
 *	Set the game name to load his hiscores
 */
Uint8	set_current_game(char *game_name);

#endif /* !GAMES_SPACEINVADERS_HISCORES_H_ */
