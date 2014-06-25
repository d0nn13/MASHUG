/*
** sfx.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 21:59:36 2014 AHAMADA Samir
** Last update Thu Jun 19 23:12:31 2014 AHAMADA Samir
*/

/**
 *	@file	sfx.h
 *	@brief	Game sound effects
 */

#ifndef GAME_COMMON_SFX_H
#define GAME_COMMON_SFX_H

#include <SDL2/SDL_audio.h>
#include "../../core/audio.h"

/**
 *	Sound effects enumeration
 */
typedef enum
  {
    BLIPSEL_SFX = 0,
    BLIPOK_SFX,
    BLIPCANCEL_SFX,
    NB_SFX
  }		t_sfx;

/**
 *	Loads sound effects in memory
 */
void	load_sounds();

/**
 *	Sound effect getter
 */
t_chunk	*get_sfx(t_sfx t);

/**
 *	Frees sound effects
 */
void	free_sounds();

#endif /* !GAME_COMMON_SFX_H */
