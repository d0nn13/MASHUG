/*
** sound_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Wed Apr 30 01:24:06 2014 AHAMADA Samir
** Last update Thu Jun 26 18:43:11 2014 AHAMADA Samir
*/

/**
 *	@file	sound_handler.c
 *	@brief	Sound handling interface
 */

#include <SDL2/SDL_audio.h>
#include "../log.h"

#include "../handlers.h"

void	play_sfx(t_chunk *s)
{
  if (!s)
    {
      SDL_LogError(AUD_LCAT, "play_sfx: s is NULL");
      return ;
    }
  s->pos = 0;
  set_audio_buffer(s, SLOT_0);
  if (SDL_GetAudioDeviceStatus(*get_audio_device()) == SDL_AUDIO_PAUSED)
    SDL_PauseAudioDevice(*get_audio_device(), 0);
}
