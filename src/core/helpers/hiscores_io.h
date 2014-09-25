/*
** hiscores.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:13 2014 ENNEBATI Yassine
** Last update Thu Sep 25 20:23:35 2014 FOFANA Ibrahim
*/

/**
 *	@file	hiscores.h
 *	@brief	Hi-Scores mode for space invaders game
 */

#ifndef GAMES_SPACEINVADERS_HISCORES_IO_H_
# define GAMES_SPACEINVADERS_HISCORES_IO_H_

/**
 *	Load HiScores
 */
Uint8	load_hiscores(t_hiscores *hiscores, char *current_game);

/**
 *	Save HiScores to system
 */
Uint8	save_hiscores(t_hiscoreholder *entry, char *current_game);

/**
 *	Free HiScores
 */
void	free_hiscores(t_hiscores *hiscores);

#endif /* !GAMES_SPACEINVADERS_HISCORES_H_ */
