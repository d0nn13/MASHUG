/*
** font_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 28 15:48:17 2014 AHAMADA Samir
** Last update Fri Jun 27 15:37:54 2014 AHAMADA Samir
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

SDL_Surface	*get_text_surface(const char *text, const TTF_Font *f, const SDL_Color *c)
{
  SDL_Surface	*t;
  SDL_Surface	*s;

  if(!ptr_chk(text, "text", FNT_LCAT, "get_text_surface") ||
     !ptr_chk(f, "font", FNT_LCAT, "get_text_surface") ||
     !ptr_chk(c, "color", FNT_LCAT, "get_text_surface"))
    return (NULL);
  t = TTF_RenderUTF8_Blended((TTF_Font *)f, text, *c);
  if (!(s = SDL_ConvertSurfaceFormat(t, PIX_FMT, 0)))
    SDL_LogError(FNT_LCAT, "get_text_surface: ", SDL_GetError());
  SDL_SetSurfaceAlphaMod(s, c->a);
  return (s);
}

void	draw_text(const char *text, const SDL_Point *o, const TTF_Font *f, const SDL_Color *c)
{
  SDL_Surface	*t;
  SDL_Surface	*s;
  SDL_Rect	z;

  if (!(t = TTF_RenderUTF8_Solid((TTF_Font *)f, text, *c)))
    {
      SDL_LogError(FNT_LCAT, "draw_text: ", TTF_GetError());
      return ;
    }
  z.x = o->x;
  z.y = o->y;
  z.w = t->w;
  z.h = t->h;
  if (!(s = SDL_ConvertSurfaceFormat(t, PIX_FMT, 0)))
    {
      SDL_LogError(FNT_LCAT, "draw_text: ", SDL_GetError());
      return ;
    }
  SDL_FreeSurface(t);
  SDL_UpdateTexture(get_bg()->tex, &z, s->pixels, s->pitch);
  SDL_RenderCopy(get_renderer(), get_bg()->tex, &z, &z);
  SDL_RenderPresent(get_renderer());
  SDL_FreeSurface(s);
  SDL_LogDebug(FNT_LCAT, "Drawn text \"%s\"", text);
}
