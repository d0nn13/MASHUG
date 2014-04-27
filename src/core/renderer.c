/*
** renderer.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 11:27:56 2014 AHAMADA Samir
** Last update Sun Apr 27 18:40:36 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "log.h"
#include "window.h"
#include "renderer.h"

static SDL_Renderer	*renderer = NULL;
static SDL_Texture	*texture = NULL;

Sint32	renderer_init()
{
  renderer = SDL_CreateRenderer(get_window(), -1, 0);
  if (!renderer)
    {
      SDL_LogError(RDR_LCAT, "Couldn't initialize renderer : %s", SDL_GetError());
      return (-1);
    }
  SDL_ShowWindow(get_window());
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  IMG_Init(IMG_INIT_PNG);
  SDL_LogInfo(RDR_LCAT, "Renderer initialization done");
  return (0);
}

void	renderer_destroy()
{
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_LogInfo(RDR_LCAT, "Renderer destroyed");
}

SDL_Renderer	*get_renderer()
{
  return (renderer);
}

SDL_Texture	*get_texture()
{
  return (texture);
}

void	set_texture(SDL_Texture *t)
{
  texture = t;
}

