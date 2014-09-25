/*
** hiscores.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:13 2014 ENNEBATI Yassine
** Last update Thu Sep 25 20:45:35 2014 FOFANA Ibrahim
*/

/**
 *	@file	hiscores.h
 *	@brief	Hi-Scores mode for space invaders game
 */

#ifndef GAMES_SPACEINVADERS_HISCORES_IO_H_
# define GAMES_SPACEINVADERS_HISCORES_IO_H_

/**
 *	@brief	Load HiScores
 *
 *	@param	hiscores Hiscores container
 *	@param	current_game The name of game to load
 *	@return	1
 */
Uint8	load_hiscores(t_hiscores *hiscores, char *current_game);

/**
 *	@brief	Save and merge the current HiScores with others
 *
 *	@param	entry The current hiscores
 *	@param	current_game The game's name of hiscores
 *	@return	1
 */
Uint8	save_hiscores(t_hiscoreholder *entry, char *current_game);

/**
*	@brief	Free HiScores allocation
 *
 *	@param	hiscores Hiscores container
 *	@param	current_game The name of game to load
 */
void	free_hiscores(t_hiscores *hiscores);

#endif /* !GAMES_SPACEINVADERS_HISCORES_H_ */
