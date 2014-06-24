/*
** audio.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 12:10:05 2014 AHAMADA Samir
** Last update Tue Jun 24 18:03:07 2014 AHAMADA Samir
*/

/**
 *	@file	audio.c
 *	@brief	Audio engine module
 */

#include <string.h>
#include <SDL2/SDL.h>
#include "log.h"
#include "audio.h"

static SDL_AudioDeviceID	dev;
static SDL_AudioSpec		conf;
static t_chunk			*slot[SLOT_NB];

/**
 *	@brief	Audio callback (internal)
 *
 *	Internal function repeatedly called by SDL to fill its audio buffer
 *
 *	@param	void *userdata
 *	@param	Uint8 *stream
 *	@param	int len
 *	@todo	C89 : Remove designated initializers
 */
static void	fill_audio_buffer(void *userdata, Uint8 *stream, int len);

Sint32		audio_init()
{
  SDL_AudioSpec	try;
  int		i;

  if (SDL_InitSubSystem(SDL_INIT_AUDIO))
    {
      SDL_LogError(AUD_LCAT, "Couldn't initialize audio : %s", SDL_GetError());
      return (-1);
    }
  try = (SDL_AudioSpec){.freq = 22050, .format = AUDIO_S16LSB, .channels = 2,
			.samples = 1024, .callback = fill_audio_buffer};
  dev = SDL_OpenAudioDevice(NULL, 0, &try, &conf, 0);
  if (!dev)
    {
      SDL_LogError(AUD_LCAT, "Couldn't initialize audio : %s", SDL_GetError());
      return (-1);
    }
  else
    {
      for (i = 0; i < SLOT_NB; ++i)
	slot[i] = NULL;
      SDL_LogInfo(AUD_LCAT, "Audio initialization done : %d channels @%d Hz, fmt=%d",
		  conf.channels, conf.freq, conf.format);
    }
  return (0);
}

SDL_AudioDeviceID	*get_audio_device()
{
  return (&dev);
}

SDL_AudioSpec	*get_audio_conf()
{
  return (&conf);
}

void	set_audio_buffer(t_chunk *c, t_slot s)
{
  if (s < SLOT_NB)
    {
      slot[s] = c;
      SDL_LogDebug(AUD_LCAT, "Loaded slot #%d", s);
    }
  else
    SDL_LogDebug(AUD_LCAT, "Slot requested is out of range (%d)", s);
}

void	audio_destroy()
{
  SDL_PauseAudioDevice(dev, 1);
  SDL_CloseAudioDevice(dev);
  SDL_QuitSubSystem(SDL_INIT_AUDIO);
  SDL_LogInfo(AUD_LCAT, "Audio destroyed");
}

static void		fill_audio_buffer(void *userdata, Uint8 *stream, int len)
{
  Sint32	rem;
  Uint8		s;

  SDL_memset(stream, 0, len);
  for (s = 0; s < SLOT_NB; ++s)
    {
      if (slot[s])
	{
	  rem = slot[s]->len - slot[s]->pos;
	  if (rem <= 0)
	    {
	      slot[s] = NULL;
	      return ;
	    }
	  len = rem < len ? rem : len;
	  SDL_MixAudioFormat(stream, &slot[s]->buf[slot[s]->pos], conf.format, len, SDL_MIX_MAXVOLUME / 2);
	  slot[s]->pos += len;
	}
    }
  userdata = (void *)userdata;
}
