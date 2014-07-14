/*
** hiscores.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat May  3 20:36:58 2014 AHAMADA Samir
** Last update Wed Jul  9 12:10:28 2014 ENNEBATI Yassine
*/

/**
 *	@file	hiscores.h
 *	@brief	Hi-Scores mode
 */

#ifndef GAME_HISCORES_H
# define GAME_HISCORES_H

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

#endif /* !GAME_HISCORES_H */
