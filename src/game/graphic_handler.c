/*
** graphic_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu May  1 18:22:44 2014 AHAMADA Samir
** Last update Sat May  3 15:25:43 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "../core/renderer.h"
#include "graphic_handler.h"

t_texture	*make_texture(SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h)
{
  t_texture	*t;

  t = malloc(sizeof(t_texture));
  if (!(t->tex = SDL_CreateTexture(r, PIX_FMT, a, w, h)))
    {
      SDL_LogError(RDR_LCAT, "Couldn't create texture : ", SDL_GetError());
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
      SDL_LogError(RDR_LCAT, "Couldn't create texture : ", SDL_GetError());
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
