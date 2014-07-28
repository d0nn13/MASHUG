/*
** audio.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 12:08:32 2014 AHAMADA Samir
** Last update Tue Jul 15 13:03:03 2014 ENNEBATI Yassine
*/

/**
 *	@file	audio.h
 *	@brief	Audio engine module
 */

#ifndef CORE_AUDIO_H_
# define CORE_AUDIO_H_

# include <SDL2/SDL_audio.h>

/**
 *	@brief   Audio chunk declaration
 */
typedef struct	s_chunk
{
  Uint8		*buf;
  Uint32	len;
  Uint32	pos;
}		t_chunk;

/**
 *	@brief	Audio slot constants definition
 *
 *	@enum	t_slot
 */
typedef enum
{
  SLOT_0 = 0,
  SLOT_1,
  SLOT_2,
  SLOT_3,
  SLOT_NB
}	t_slot;

/**
 *	@brief	Initializes engine's Audio module
 *
 *	@return	0 if the audio initialization was succeeded
 *	@return -1 if the audio initialization failed
 */
Sint32	audio_init();

/**
 *	@brief	Loads an audio chunk into an audio slot
 *
 *	@param	c The audio chunk to load
 *	@param	t The slot to load into
 */
void	set_audio_buffer(t_chunk *c, t_slot t);

/**
 *	@brief	Audio device getter
 *
 *	@return	a pointer to the engine's SDL_AudioDeviceID struct
 */
SDL_AudioDeviceID	*get_audio_device();

/**
 *	@brief	Returns audio configuration structure
 *
 *	@return	a pointer on a SDL_AudioSpec struct
 */
SDL_AudioSpec	*get_audio_conf();

/**
 *	@brief	Destroys the Audio SubSystem
 */
void	audio_destroy();

#endif /* !CORE_AUDIO_H_ */
