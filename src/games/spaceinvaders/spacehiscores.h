/*
** spacehiscores.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:13 2014 ENNEBATI Yassine
** Last update Tue Jul 15 13:14:27 2014 ENNEBATI Yassine
*/

/**
 *	@file	spacehiscores.h
 *	@brief	Hi-Scores mode for space invaders game
 */

#ifndef GAMES_SPACEINVADERS_SPACEHISCORES_H_
# define GAMES_SPACEINVADERS_SPACEHISCORES_H_

/**
 *	Main HiScores-mode routine
 */
void	hiscores();

/**
 *	Load HiScores from system
 */
Sint32	load_hiscores();

/**
 *	Save HiScores to system
 */
Sint32	save_hiscore();

#endif /* !GAMES_SPACEINVADERS_SPACEHISCORES_H_ */