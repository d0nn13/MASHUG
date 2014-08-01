/*
** renderer.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:27:56 2014 AHAMADA Samir
** Last update Mon Jul 14 02:10:08 2014 ENNEBATI Yassine
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

#include "renderer.h"

static SDL_Renderer	*renderer = NULL;

Sint32	renderer_init()
{
  renderer = SDL_CreateRenderer(get_window(), -1, SDL_RENDERER_SOFTWARE);
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
  SDL_ShowWindow(get_window());
  SDL_SetRenderDrawColor(renderer, 10, 30, 10, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_LogInfo(RDR_LCAT, "Renderer initialization done");
  return (0);
}

SDL_Renderer	*get_renderer()
{
  return (SDL_GetRenderer(get_window()));
}

void	renderer_destroy()
{
  TTF_Quit();
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_LogInfo(RDR_LCAT, "Renderer destroyed");
}
