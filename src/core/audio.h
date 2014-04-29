/*
** audio.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 12:08:32 2014 AHAMADA Samir
** Last update Wed Apr 30 01:13:27 2014 AHAMADA Samir
*/

#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_audio.h>

/**
 *	Initializes Audio SubSystem
 */
Sint32	audio_init();

/**
 *	Destroys Audio SubSystem
 */
void	audio_destroy();


SDL_AudioSpec	*get_audio_conf();

/**
 *	Audio callback
 */
void	callback(void *userdata, Uint8 *stream, int len);
#endif /* !AUDIO_H */
