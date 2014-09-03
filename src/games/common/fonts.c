/*
** fonts.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 23:21:54 2014 AHAMADA Samir
** Last update Sat Aug 16 16:25:49 2014 ENNEBATI Yassine
*/

#include <SDL2/SDL_ttf.h>
#include "../../core/log.h"

#include "fonts.h"

static t_font	fonts[NB_FNT] = {
  {NULL, "atari24", "media/fonts/atari.ttf", 24},
  {NULL, "atari18", "media/fonts/atari.ttf", 18},
  {NULL, "cosmic48", "media/fonts/cosmic.ttf", 48},
  {NULL, "cosmic24", "media/fonts/cosmic.ttf", 24},
  {NULL, "cosmic18", "media/fonts/cosmic.ttf", 18},
  {NULL, "prstartk24", "media/fonts/prstartk.ttf", 24},
  {NULL, "prstartk28", "media/fonts/prstartk.ttf", 28},
  {NULL, "prstartk18", "media/fonts/prstartk.ttf", 18}
};

void	load_common_fonts()
{
  Uint8	i;
  Uint8	c;

  for (i = 0, c = 0; i < NB_FNT; i++)
  {
    fonts[i].font = TTF_OpenFont(fonts[i].path, fonts[i].size);
    if (fonts[i].font == NULL)
      SDL_LogError(FNT_LCAT, "Couldn't load font '%s': %s", fonts[i].name,
		   TTF_GetError());
    else
    {
      SDL_LogVerbose(FNT_LCAT, "Font '%s' loaded", fonts[i].name);
      ++c;
    }
  }
  if (c == NB_FNT)
    SDL_LogInfo(FNT_LCAT, "Common fonts successfully loaded");
}

TTF_Font	*get_common_font(t_common_font t)
{
  return (fonts[t].font);
}

void	free_common_fonts()
{
  Uint8	i;

  for (i = 0; i < NB_FNT; ++i)
  {
    if (fonts[i].font)
    {
      TTF_CloseFont(fonts[i].font);
      fonts[i].font = NULL;
    }
  }
  SDL_LogInfo(FNT_LCAT, "Common fonts destroyed");
}
