/*
** sfx.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 21:59:36 2014 AHAMADA Samir
** Last update Mon Jul 14 13:26:33 2014 ENNEBATI Yassine
*/

/**
 *	@file	sfx.h
 *	@brief	Common game sound sffects
 */

#ifndef GAMES_COMMON_SFX_H
# define GAMES_COMMON_SFX_H

# include <SDL2/SDL_audio.h>
# include "../../core/audio.h"

/**
 *	Common sound effects enumeration
 */
typedef enum
  {
    BLIPSEL_SFX = 0,
    BLIPOK_SFX,
    BLIPCANCEL_SFX,
    NB_SFX
  }		t_common_sfx;

/**
 *	Loads sound effects in memory
 */
void	load_common_sfx();

/**
 *	Sound effect getter
 */
t_chunk	*get_common_sfx(t_common_sfx t);

/**
 *	Frees sound effects
 */
void	free_common_sfx();

#endif /* !GAMES_COMMON_SFX_H */
