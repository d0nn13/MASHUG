/*
** audio.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 12:08:32 2014 AHAMADA Samir
** Last update Thu Jun 19 20:58:35 2014 AHAMADA Samir
*/

/**
 *	@file	audio.h
 *	@brief	Audio engine module
 */

#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_audio.h>

/**
 * @struct t_chunk
 * @brief Audio chunk declaration
 */
typedef struct	s_chunk
{
  Uint8		*buf;
  Uint32	len;
  Uint32	pos;
}		t_chunk;

/**
 * @enum t_slot
 * @brief Slot constants
 *	Audio slot definition
 */
typedef enum
  {
    SLOT_0 = 0,
    SLOT_1,
    SLOT_2,
    SLOT_3,
    SLOT_NB
  }		t_slot;

/**
 * @fn Sint32 audio_init()
 * @return 0 if the audio initialization was succeeded
 * @brief Initializes Audio SubSystem
 */
Sint32	audio_init();

/**
 * @fn void  set_audio_buffer(t_chunk *c, t_slot t)
 * @params t_chunk *c
 * @params t_slot *t
 * @return void
 * @brief Load an audio chunk 'c', in a audio slot 't'
 */
void	set_audio_buffer(t_chunk *c, t_slot t);

/**
 * @fn SDL_AudioDeviceID *get_audio_device()
 * @return a pointer on a SDL_AudioDeviceID struct
 * @brief	Audio device getter
 */
SDL_AudioDeviceID	*get_audio_device();

/**
 * @fn SDL_AudioSpec  *get_audio_conf()
 * @return a pointer on a SDL_AudioSpec struct
 * @brief Returns audio conf
 */
SDL_AudioSpec	*get_audio_conf();

/**
 * @fn void audio_destroy()
 * @return void
 * @brief Destroys Audio SubSystem
 */
void	audio_destroy();

/**
 * @fn void fill_audio_buffer(void *userdata, Uint8 *stream, int len)
 * @params void *userdata
 * @params Uint8 *stream
 * @params int len
 * @return void
 * @brief Audio callback
 *
 */
void	fill_audio_buffer(void *userdata, Uint8 *stream, int len);

#endif /* !AUDIO_H */
