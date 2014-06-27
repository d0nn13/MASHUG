/*
** graphic_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu May  1 18:22:44 2014 AHAMADA Samir
** Last update Tue Jun 24 23:01:47 2014 AHAMADA Samir
*/

/**
 *	@file	graphic_handler.c
 *	@brief	Graphic handling interface
 */

#include "../log.h"
#include "../renderer.h"

#include "../handlers.h"

t_texture	*make_texture(SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h)
{
  t_texture	*t;

  t = malloc(sizeof(t_texture));
  if (!(t->tex = SDL_CreateTexture(r, PIX_FMT, a, w, h)))
    {
      SDL_LogError(GFX_LCAT, "Couldn't create texture : ", SDL_GetError());
      return (NULL);
    }
  SDL_SetTextureBlendMode(t->tex, SDL_BLENDMODE_BLEND);
  t->w = w;
  t->h = h;
  return (t);
}

t_texture	*make_texture_from_surface(SDL_Renderer *r, SDL_Surface *s)
{
  t_texture	*t;

  t = malloc(sizeof(t_texture));
  if (!(t->tex = SDL_CreateTextureFromSurface(r, s)))
    {
      SDL_LogError(GFX_LCAT, "Couldn't create texture : ", SDL_GetError());
      return (NULL);
    }
  SDL_SetTextureBlendMode(t->tex, SDL_BLENDMODE_BLEND);
  t->w = s->w;
  t->h = s->h;
  return (t);
}

void		free_texture(t_texture *t)
{
  SDL_DestroyTexture(t->tex);
  free(t);
}
