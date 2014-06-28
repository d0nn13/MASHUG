/*
** fonts.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 23:21:54 2014 AHAMADA Samir
** Last update Sat Jun 28 18:04:15 2014 AHAMADA Samir
*/

#include <SDL2/SDL_ttf.h>
#include "../../core/log.h"

#include "fonts.h"

static TTF_Font	*common_fonts[NB_FNT];

void	load_common_fonts()
{
  common_fonts[ATARI24_FNT] = TTF_OpenFont("media/fonts/atari.ttf", 24);
  common_fonts[ATARI18_FNT] = TTF_OpenFont("media/fonts/atari.ttf", 18);
  common_fonts[COSMIC48_FNT] = TTF_OpenFont("media/fonts/cosmic.ttf", 48);
  common_fonts[COSMIC24_FNT] = TTF_OpenFont("media/fonts/cosmic.ttf", 24);
  common_fonts[COSMIC18_FNT] = TTF_OpenFont("media/fonts/cosmic.ttf", 18);
  common_fonts[COSMIC12_FNT] = TTF_OpenFont("media/fonts/cosmic.ttf", 12);
  SDL_LogInfo(FNT_LCAT, "Fonts loaded.");
}

TTF_Font	*get_common_font(t_common_font t)
{
  return (common_fonts[t]);
}

void		free_common_fonts()
{
  Uint8	i;

  for (i = 0; i < NB_FNT; ++i)
    TTF_CloseFont(common_fonts[i]);
  SDL_LogInfo(FNT_LCAT, "Fonts destroyed.");
}
