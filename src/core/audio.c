/*
** audio.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 12:10:05 2014 AHAMADA Samir
** Last update Wed Apr 30 01:38:03 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include "log.h"
#include "audio.h"

static SDL_AudioDeviceID	audio;
static SDL_AudioSpec		conf;

Sint32	audio_init()
{
  SDL_AudioSpec	try;

  if (SDL_InitSubSystem(SDL_INIT_AUDIO))
    {
      SDL_LogError(AUD_LCAT, "Couldn't initialize audio : %s", SDL_GetError());
      return (-1);
    }
  try = (SDL_AudioSpec){.freq = 22050, .format = AUDIO_S16LSB, .channels = 2,
			.samples = 4096, .callback = callback };
  audio = SDL_OpenAudioDevice(NULL, 0, &try, &conf, 0);
  if (!audio)
    {
      SDL_LogError(AUD_LCAT, "Couldn't initialize audio : %s", SDL_GetError());
      return (-1);
    }
  else
    SDL_LogInfo(AUD_LCAT, "Audio initialization done : %d channels @%d Hz, fmt=%d",
		conf.channels, conf.freq, conf.format);
 return (0);
}

void	audio_destroy()
{
  SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

SDL_AudioSpec	*get_audio_conf()
{
  return (&conf);
}

void	callback(void *userdata, Uint8 *stream, int len)
{
  int	i;

  for (i = 0; i < len; ++i)
    stream[i] = 127;
  userdata = (void *)userdata; 
}
