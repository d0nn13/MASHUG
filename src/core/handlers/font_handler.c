/*
** font_handler.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 28 15:48:17 2014 AHAMADA Samir
** Last update Wed Jul 23 17:02:45 2014 ENNEBATI Yassine
*/

/**
 *	@file	font_handler.c
 *	@brief	Font handling interface
 */

#include <SDL2/SDL_ttf.h>
#include "../log.h"
#include "../renderer.h"
#include "../graphics.h"
#include "../helpers.h"

#include "../handlers.h"

SDL_Surface	*get_text_surface(char const *text,
				  TTF_Font const *f,
				  SDL_Color const *c)
{
  SDL_Surface	*t;
  SDL_Surface	*s;

  if (!ptr_chk(text, "text", FNT_LCAT, "get_text_surface") ||
     !ptr_chk(f, "font", FNT_LCAT, "get_text_surface") ||
     !ptr_chk(c, "color", FNT_LCAT, "get_text_surface"))
    return (NULL);
  t = TTF_RenderUTF8_Blended((TTF_Font *)f, text, *c);
  if (!(s = SDL_ConvertSurfaceFormat(t, PIX_FMT, 0)))
    SDL_LogError(FNT_LCAT, "get_text_surface: ", SDL_GetError());
  SDL_SetSurfaceAlphaMod(s, c->a);
  return (s);
}

void		draw_text(char const *text,
			  SDL_Point const *o,
			  TTF_Font const *f,
			  SDL_Color const *c)
{
  SDL_Surface	*t;
  SDL_Surface	*s;
  SDL_Rect	z;

  if (!ptr_chk(text, "text", FNT_LCAT, "draw_text") ||
      !ptr_chk(f, "font", FNT_LCAT, "draw_text"))
    return ;
  if (!(t = TTF_RenderUTF8_Solid((TTF_Font *)f, text, *c)))
  {
    SDL_LogError(FNT_LCAT, "draw_text: ", TTF_GetError());
    return ;
  }
  z = rect_factory(o->x, o->y, t->w, t->h);
  if (!(s = SDL_ConvertSurfaceFormat(t, PIX_FMT, 0)))
  {
    SDL_LogError(FNT_LCAT, "draw_text: ", SDL_GetError());
    return ;
  }
  SDL_FreeSurface(t);
  SDL_UpdateTexture(get_bg()->tex, &z, s->pixels, s->pitch);
  SDL_RenderCopy(get_renderer(), get_bg()->tex, &z, &z);
  SDL_FreeSurface(s);
  SDL_LogVerbose(FNT_LCAT, "Drawn text '%s'", text);
}
