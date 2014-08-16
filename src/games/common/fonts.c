/*
** fonts.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 23:21:54 2014 AHAMADA Samir
** Last update Sat Aug 16 15:35:40 2014 ENNEBATI Yassine
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
  {NULL, "prstartk24", "media/fonts/prstartk.ttf", 24}
};

void	load_common_fonts()
{
  Uint8	it;

  for (it = 0; it < NB_FNT; it++)
  {
    fonts[it].font = TTF_OpenFont(fonts[it].path, fonts[it].size);
    if (fonts[it].font == NULL)
      SDL_LogError(FNT_LCAT, "Error on load font : %s\n", TTF_GetError());
    else
      SDL_LogVerbose(FNT_LCAT, "Font success load for: %s\n", fonts[it].name);
  }
}

TTF_Font	*get_common_font(t_common_font t)
{
  return (fonts[t].font);
}

void		free_common_fonts()
{
  Uint8	i;

  for (i = 0; i < NB_FNT; ++i)
  {
    TTF_CloseFont(fonts[i].font);
    memset(&(fonts[i].font), 0, sizeof(fonts[i].font));
  }
  SDL_LogInfo(FNT_LCAT, "Common fonts destroyed");
}
