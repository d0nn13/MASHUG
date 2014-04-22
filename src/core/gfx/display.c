/*
** display.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 11:38:31 2014 AHAMADA Samir
** Last update Tue Apr 22 14:27:57 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_error.h>
#include "display.h"

#define VID_CAT	SDL_LOG_CATEGORY_VIDEO
#define RDR_CAT	SDL_LOG_CATEGORY_RENDER

static SDL_Window	*window = NULL;
static SDL_Renderer	*renderer = NULL;

int	Dspl_init()
{
  window = SDL_CreateWindow("-=  S P A C E  I N V A D E R S  =-", 100, 100,
  			    WIN_WIDTH, WIN_HEIGHT, 0);
  if (!window)
    {
      SDL_LogError(VID_CAT, "Couldn't initialize window : %s",
		   SDL_GetError());
      return (1);
    }
  SDL_LogInfo(VID_CAT, "Window initialization done");
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
    {
      SDL_LogError(RDR_CAT, "Couldn't initialize renderer : %s",
		   SDL_GetError());
      return (1);
    }
  SDL_LogInfo(RDR_CAT, "Renderer initialization done");
  return (0);
}

void	Dspl_destroy()
{
  SDL_DestroyWindow(window);
  SDL_LogInfo(VID_CAT, "Window destroyed");
  SDL_DestroyRenderer(renderer);
  SDL_LogInfo(RDR_CAT, "Renderer destroyed");
}

SDL_Window	*Dspl_getWindow()
{
  return (window);
}

SDL_Renderer	*Dspl_getRenderer()
{
  return (renderer);
}
