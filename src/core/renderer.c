/*
** renderer.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:27:56 2014 AHAMADA Samir
** Last update Tue Aug 12 22:22:55 2014 ENNEBATI Yassine
*/

/**
 *	@file	renderer.c
 *	@brief	Rendering engine
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "log.h"
#include "window.h"
#include "video_debug.h"

#include "renderer.h"

#ifndef SOFT_RENDER
# define RENDERER_FLAGS	SDL_RENDERER_ACCELERATED
#else
# define RENDERER_FLAGS	SDL_RENDERER_SOFTWARE
#endif

static SDL_Renderer	*renderer = NULL;

Sint32	renderer_init()
{
  renderer = SDL_CreateRenderer(get_window(), -1, RENDERER_FLAGS);
  if (!renderer)
  {
    SDL_LogError(RDR_LCAT, "Couldn't initialize renderer : %s", SDL_GetError());
    return (-1);
  }
  if (IMG_Init(IMG_INIT_PNG))
  {
    /* SDL_LogError(RDR_LCAT, SDL_GetError()); */
    /* return (-1); */
  }
  if (TTF_Init())
  {
    SDL_LogCritical(RDR_LCAT, SDL_GetError());
    return (-1);
  }
  renderer_debug(renderer);
  SDL_ShowWindow(get_window());
  SDL_SetRenderDrawColor(renderer, 10, 30, 10, 255);
  SDL_RenderClear(renderer);
  SDL_LogInfo(RDR_LCAT, "Renderer initialization done");
  return (0);
}

SDL_Renderer	*get_renderer()
{
  return (SDL_GetRenderer(get_window()));
}

void			renderer_clear(SDL_Color const *c)
{
  SDL_Color const	black = {0, 0, 0, 255};
  SDL_Color		col;

  col = !c ? black : *c;
  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
}

void	renderer_destroy()
{
  TTF_Quit();
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_LogInfo(RDR_LCAT, "Renderer destroyed");
}
