/*
** sound_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Apr 30 01:22:34 2014 AHAMADA Samir
** Last update Mon Jun 23 19:31:02 2014 AHAMADA Samir
*/

/**
 *	@file	sound_handler.h
 *	@brief	Sound handling interface
 */

#ifndef SOUND_HANDLER
#define SOUND_HANDLER

#include "../common/sfx.h"
#include "../common/bgm.h"

/**
 *	@brief Plays a sound effect.
 *
 *	@param The desired sound effect in t_sfx enumeration
 */
void	play_sfx(t_sfx s);

#endif /* !SOUND_HANDLER */
