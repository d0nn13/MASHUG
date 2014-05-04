/*
** sfx.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 22:01:07 2014 AHAMADA Samir
** Last update Thu May  1 14:10:17 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "../core/audio.h"
#include "sound_handler.h"
#include "sfx.h"

static t_chunk	Sfx[NB_SFX];

void	load_sounds()
{
  t_sfx	i;

  SDL_LoadWAV("media/sfx/blip_22k.wav", get_audio_conf(), &Sfx[BLIP_SFX].buf,
	      &Sfx[BLIP_SFX].len);
  for (i = 0; i < NB_SFX; ++i)
    Sfx[i].pos = 0;
  SDL_LogInfo(AUD_LCAT, "Sounds loaded.");
}

t_chunk	*get_sfx(t_sfx t)
{
  return (&Sfx[t]);
}

void	free_sounds()
{
  Uint8	i;

  for (i = 0; i < NB_SFX; ++i)
    SDL_FreeWAV(Sfx[i].buf);
  SDL_LogInfo(AUD_LCAT, "Sounds destroyed.");
}
