/*
** sfx.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 22:01:07 2014 AHAMADA Samir
** Last update Wed Apr 30 01:36:05 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "../core/audio.h"
#include "sound_handler.h"
#include "sfx.h"

static t_wav	Sfx[1];

void	load_sounds()
{
  SDL_LoadWAV("media/sfx/blip_22k.wav", get_audio_conf(), &Sfx[BLIP_SFX].buf,
	      &Sfx[BLIP_SFX].len);
  SDL_LogInfo(AUD_LCAT, "Sounds loaded.");
}

void	free_sounds()
{
  Uint8	i;

  for (i = 0; i < LAST_SFX; ++i)
    SDL_FreeWAV(Sfx[i].buf);
  SDL_LogInfo(AUD_LCAT, "Sounds destroyed.");
}
