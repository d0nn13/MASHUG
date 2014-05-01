/*
** audio.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 12:08:32 2014 AHAMADA Samir
** Last update Thu May  1 12:05:03 2014 AHAMADA Samir
*/

#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_audio.h>

typedef struct	s_chunk
{
  Uint8		*buf;
  Uint32	len;
  Uint32	pos;
}		t_chunk;


typedef enum
  {
    SLOT_0 = 0,
    SLOT_1,
    SLOT_2,
    SLOT_3,
    SLOT_NB
  }		t_slot;

/**
 *	Initializes Audio SubSystem
 */
Sint32	audio_init();

/**
 *
 */
void	set_audio_buffer(t_chunk *c, t_slot t);

/**
 *
 */
SDL_AudioDeviceID	*get_audio_device();

/**
 *	Returns audio conf
 */
SDL_AudioSpec	*get_audio_conf();

/**
 *	Destroys Audio SubSystem
 */
void	audio_destroy();

/**
 *	Audio callback
 */
void	fill_audio_buffer(void *userdata, Uint8 *stream, int len);

#endif /* !AUDIO_H */
