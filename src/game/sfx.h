/*
** sfx.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:59:36 2014 AHAMADA Samir
** Last update Sun May  4 21:01:37 2014 AHAMADA Samir
*/

#ifndef SFX_H
#define SFX_H

#include <SDL2/SDL_audio.h>
#include "../core/audio.h"

typedef enum
  {
    BLIPSEL_SFX = 0,
    BLIPOK_SFX,
    BLIPCANCEL_SFX,
    NB_SFX
  }		t_sfx;

void	load_sounds();

t_chunk	*get_sfx(t_sfx t);

void	free_sounds();

#endif /* !SFX_H */
