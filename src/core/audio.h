/*
** audio.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 12:08:32 2014 AHAMADA Samir
** Last update Sun Apr 27 17:50:54 2014 AHAMADA Samir
*/

#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_audio.h>

/**
 *	Initializes Audio SubSystem
 */
Uint32	audio_init();

/**
 *	Destroys Audio SubSystem
 */
void	audio_destroy();

#endif /* !AUDIO_H */
