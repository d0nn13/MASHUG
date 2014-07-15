/*
** sfx.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 22:01:07 2014 AHAMADA Samir
** Last update Sat Jun 28 18:05:01 2014 AHAMADA Samir
*/

#include "../../core/log.h"
#include "../../core/audio.h"
#include "../../core/handlers.h"

#include "sfx.h"

#define SELECT_WAV	"media/sfx/blip_select.wav"
#define OK_WAV		"media/sfx/blip_ok.wav"
#define CANCEL_WAV	"media/sfx/blip_cancel.wav"

static t_chunk	common_sfx[NB_SFX];

void		load_common_sfx()
{
  t_common_sfx	i;

  if (!SDL_LoadWAV(SELECT_WAV, get_audio_conf(), &common_sfx[BLIPSEL_SFX].buf,
		   &common_sfx[BLIPSEL_SFX].len) ||
      !SDL_LoadWAV(OK_WAV, get_audio_conf(), &common_sfx[BLIPOK_SFX].buf,
		   &common_sfx[BLIPOK_SFX].len) ||
      !SDL_LoadWAV(CANCEL_WAV, get_audio_conf(), &common_sfx[BLIPCANCEL_SFX].buf,
		   &common_sfx[BLIPCANCEL_SFX].len))
    SDL_LogError(AUD_LCAT, SDL_GetError());
  else
    SDL_LogInfo(AUD_LCAT, "Sounds loaded");
  for (i = 0; i < NB_SFX; ++i)
    common_sfx[i].pos = 0;
}

t_chunk	*get_common_sfx(t_common_sfx t)
{
  return (&common_sfx[t]);
}

void	free_common_sfx()
{
  Uint8	i;

  for (i = 0; i < NB_SFX; ++i)
    SDL_FreeWAV(common_sfx[i].buf);
  SDL_LogInfo(AUD_LCAT, "Sounds destroyed");
}
