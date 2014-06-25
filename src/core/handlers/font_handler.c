/*
** font_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 28 15:48:17 2014 AHAMADA Samir
** Last update Tue Jun 24 23:02:00 2014 AHAMADA Samir
*/

/**
 *	@file	font_handler.c
 *	@brief	Font handling interface
 */

#include <SDL2/SDL_ttf.h>
#include "../log.h"
#include "../renderer.h"
#include "../graphics.h"
#include "../handlers.h"

SDL_Surface	*get_text_surface(const char *text, TTF_Font *f, SDL_Color *c)
{
  SDL_Surface	*t;
  SDL_Surface	*s;

  t = TTF_RenderUTF8_Blended(f, text, *c);
  if (!(s = SDL_ConvertSurfaceFormat(t, PIX_FMT, 0)))
    SDL_LogError(FNT_LCAT, SDL_GetError());
  SDL_SetSurfaceAlphaMod(s, c->a);
  return (s);
}

void	draw_text(const char *text, SDL_Point *o, TTF_Font *f, SDL_Color *c)
{
  SDL_Surface	*t;
  SDL_Surface	*s;
  SDL_Rect	z;

  if (!(t = TTF_RenderUTF8_Solid(f, text, *c)))
    {
      SDL_LogError(FNT_LCAT, TTF_GetError());
      return ;
    }
  z = (SDL_Rect){o->x, o->y, t->w, t->h};
  if (!(s = SDL_ConvertSurfaceFormat(t, PIX_FMT, 0)))
    {
      SDL_LogError(FNT_LCAT, SDL_GetError());
      return ;
    }
  SDL_FreeSurface(t);
  SDL_UpdateTexture(get_bg()->tex, &z, s->pixels, s->pitch);
  SDL_RenderCopy(get_renderer(), get_bg()->tex, &z, &z);
  SDL_RenderPresent(get_renderer());
  SDL_FreeSurface(s);
  SDL_LogDebug(FNT_LCAT, "Drawn text \"%s\"", text);
}
