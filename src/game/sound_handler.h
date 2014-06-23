/*
** sound_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Apr 30 01:22:34 2014 AHAMADA Samir
** Last update Thu Jun 19 22:24:37 2014 AHAMADA Samir
*/

/**
 *	@file	sound_handler.h
 *	@brief	Sound handling interface
 */

#ifndef SOUND_HANDLER
#define SOUND_HANDLER

#include "sfx.h"
#include "bgm.h"

/**
 *	@param One of the sound effects enumeration
 *	@brief Plays a sound effect
 */
void	play_sfx(t_sfx s);

#endif /* !SOUND_HANDLER */
