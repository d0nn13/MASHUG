/*
** graphic_handler.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu May  1 18:22:44 2014 AHAMADA Samir
** Last update Fri Jun 27 16:03:37 2014 AHAMADA Samir
*/

/**
 *	@file	graphic_handler.c
 *	@brief	Graphic handling interface
 */

#include "../../base/memory.h"
#include "../log.h"
#include "../renderer.h"

#include "../handlers.h"

t_texture	*make_texture(const SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h)
{
  t_texture	*t;

  if (!ptr_chk(r, "renderer", GFX_LCAT, "make_texture"))
    return (NULL);
  t = mem_alloc(sizeof(t_texture));
  if (!(t->tex = SDL_CreateTexture((SDL_Renderer *)r, PIX_FMT, a, w, h)))
    {
      SDL_LogError(GFX_LCAT, "make_texture: ", SDL_GetError());
      return (NULL);
    }
  SDL_SetTextureBlendMode(t->tex, SDL_BLENDMODE_BLEND);
  t->w = w;
  t->h = h;
  return (t);
}

t_texture	*make_texture_from_surface(const SDL_Renderer *r, const SDL_Surface *s)
{
  t_texture	*t;

  if (!ptr_chk(r, "renderer", GFX_LCAT, "make_texture") ||
      !ptr_chk(s, "surface", GFX_LCAT, "make_texture"))
    return (NULL);
  t = mem_alloc(sizeof(t_texture));
  if (!(t->tex = SDL_CreateTextureFromSurface((SDL_Renderer *)r,
	  (SDL_Surface *)s)))
    {
      SDL_LogError(GFX_LCAT, "make_texture_from_surface: ", SDL_GetError());
      return (NULL);
    }
  SDL_SetTextureBlendMode(t->tex, SDL_BLENDMODE_BLEND);
  t->w = s->w;
  t->h = s->h;
  return (t);
}

void		free_texture(t_texture *t)
{
  if (!ptr_chk(t, "texture", GFX_LCAT, "free_texture"))
    return ;
  SDL_DestroyTexture(t->tex);
  mem_free(t);
}
