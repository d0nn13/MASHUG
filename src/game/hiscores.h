/*
** hiscores.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat May  3 20:36:58 2014 AHAMADA Samir
** Last update Thu Jun 26 17:19:38 2014 AHAMADA Samir
*/

/**
 *	@file	hiscores.h
 *	@brief	Hi-Scores mode
 */

#ifndef HISCORES_H
# define HISCORES_H

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

#endif /* !HI_SCORES */
