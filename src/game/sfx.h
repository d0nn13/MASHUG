/*
** sfx.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:59:36 2014 AHAMADA Samir
** Last update Thu May  1 14:10:23 2014 AHAMADA Samir
*/

#ifndef SFX_H
#define SFX_H

#include <SDL2/SDL_audio.h>
#include "../core/audio.h"

typedef enum
  {
    BLIP_SFX = 0,
    NB_SFX
  }		t_sfx;

void	load_sounds();

t_chunk	*get_sfx(t_sfx t);

void	free_sounds();

#endif /* !SFX_H */
