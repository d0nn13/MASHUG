/*
** fonts.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 23:21:54 2014 AHAMADA Samir
** Last update Mon Apr 28 16:32:15 2014 AHAMADA Samir
*/

#include <SDL2/SDL_ttf.h>
#include "../core/log.h"
#include "gamedefs.h"

#include "fonts.h"

static TTF_Font	*Fonts[4];

void	load_fonts()
{
  Fonts[ATARI24_FNT] = TTF_OpenFont("media/fonts/atari.ttf", 24);
  Fonts[ATARI18_FNT] = TTF_OpenFont("media/fonts/atari.ttf", 18);
  Fonts[COSMIC18_FNT] = TTF_OpenFont("media/fonts/cosmic.ttf", 18);
  Fonts[COSMIC12_FNT] = TTF_OpenFont("media/fonts/cosmic.ttf", 12);
  SDL_LogInfo(FNT_LCAT, "Fonts loaded.");
}

TTF_Font	*get_font(t_font t)
{
  return (Fonts[t]);
}

void		free_fonts()
{
  Uint8	i;

  for (i = 0; i < LAST_FNT; ++i)
    TTF_CloseFont(Fonts[i]);
  SDL_LogInfo(FNT_LCAT, "Fonts destroyed.");
}
