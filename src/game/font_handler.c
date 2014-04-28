/*
** font_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 28 15:48:17 2014 AHAMADA Samir
** Last update Mon Apr 28 17:35:45 2014 AHAMADA Samir
*/

#include <SDL2/SDL_ttf.h>
#include "../core/log.h"
#include "../core/renderer.h"
#include "gamedefs.h"
#include "font_handler.h"

SDL_Surface	*get_text_surface(const char *text, t_font f, SDL_Color c)
{
  SDL_Surface	*s;

  s = TTF_RenderUTF8_Blended(get_font(f), text, c);
  return (s);
}

void	draw_text(const char *text, SDL_Point *orig, t_font f, SDL_Color c)
{
  SDL_Surface	*s;

  s = TTF_RenderUTF8_Blended(get_font(f), text, c);
  set_texture(SDL_CreateTextureFromSurface(get_renderer(), s));
  SDL_SetTextureBlendMode(get_texture(), SDL_BLENDMODE_BLEND);
  SDL_RenderCopy(get_renderer(), get_texture(), NULL,
		 &(SDL_Rect){orig->x, orig->y, s->w, s->h});
  SDL_RenderPresent(get_renderer());
  SDL_FreeSurface(s);
  SDL_LogInfo(FNT_LCAT, "Drawn text \"%s\"", text);
}
