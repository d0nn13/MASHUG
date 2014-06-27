/*
** sfx.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 22:01:07 2014 AHAMADA Samir
** Last update Tue Jun 24 23:03:58 2014 AHAMADA Samir
*/

#include "../../core/log.h"
#include "../../core/audio.h"
#include "../../core/handlers.h"

#include "sfx.h"

#define SELECT_WAV	"media/sfx/blip_select.wav"
#define OK_WAV		"media/sfx/blip_ok.wav"
#define CANCEL_WAV	"media/sfx/blip_cancel.wav"

static t_chunk	Sfx[NB_SFX];

void	load_sounds()
{
  t_sfx	i;
  if (!SDL_LoadWAV(SELECT_WAV, get_audio_conf(), &Sfx[BLIPSEL_SFX].buf,
		   &Sfx[BLIPSEL_SFX].len) ||
      !SDL_LoadWAV(OK_WAV, get_audio_conf(), &Sfx[BLIPOK_SFX].buf,
		   &Sfx[BLIPOK_SFX].len) ||
      !SDL_LoadWAV(CANCEL_WAV, get_audio_conf(), &Sfx[BLIPCANCEL_SFX].buf,
		   &Sfx[BLIPCANCEL_SFX].len))
    SDL_LogError(AUD_LCAT, SDL_GetError());
  else
    SDL_LogInfo(AUD_LCAT, "Sounds loaded");
  for (i = 0; i < NB_SFX; ++i)
    Sfx[i].pos = 0;
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
  SDL_LogInfo(AUD_LCAT, "Sounds destroyed");
}
