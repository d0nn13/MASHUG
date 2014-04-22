/*
** display.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 11:38:31 2014 AHAMADA Samir
** Last update Tue Apr 22 17:51:50 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rwops.h>
#include "display.h"

#define VID_CAT	SDL_LOG_CATEGORY_VIDEO
#define RDR_CAT	SDL_LOG_CATEGORY_RENDER

static SDL_Window	*window = NULL;
static SDL_Renderer	*renderer = NULL;
static SDL_Texture	*texture = NULL;

uInt32	Dspl_init()
{
  SDL_Surface	*sur;

  window = SDL_CreateWindow("-=  S P A C E  I N V A D E R S  =-",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
 			    WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
  if (!window)
    {
      SDL_LogError(VID_CAT, "Couldn't initialize window : %s", SDL_GetError());
      return (1);
    }
  SDL_LogInfo(VID_CAT, "Window initialization done");
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  if (!renderer)
    {
      SDL_LogError(RDR_CAT, "Couldn't initialize renderer : %s", SDL_GetError());
      return (1);
    }
  SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
  SDL_RenderClear(renderer);
  SDL_LogInfo(RDR_CAT, "Renderer initialization done");

  sur = SDL_LoadBMP_RW(SDL_RWFromFile("media/gfx/checker-tile-100px.bmp", "r"), 1);
  texture = SDL_CreateTextureFromSurface(renderer, sur);

  return (0);
}

void	Dspl_destroy()
{
  SDL_DestroyRenderer(renderer);
  SDL_LogInfo(RDR_CAT, "Renderer destroyed");
  SDL_DestroyWindow(window);
  SDL_LogInfo(VID_CAT, "Window destroyed");
}

SDL_Window	*Dspl_getWindow()
{
  return (window);
}

SDL_Renderer	*Dspl_getRender()
{
  return (renderer);
}

SDL_Texture	*Dspl_getTexture()
{
  return (texture);
}
