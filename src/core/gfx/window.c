/*
** window.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 11:38:31 2014 AHAMADA Samir
** Last update Mon Apr 21 12:40:33 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <SDL2/SDL_error.h>
#include "window.h"

static SDL_Window	*window = NULL;
static SDL_Renderer	*renderer = NULL;

int	Win_init()
{
  window = SDL_CreateWindow("-=  S P A C E  I N V A D E R S  =-", 100, 100,
			    WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
  if (!window)
    return (printf("[WINDOW] %s\n", SDL_GetError()));
  else
    printf("[WINDOW] %s\n", "Window initialized");
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
    return (printf("[WINDOW] %s\n", SDL_GetError()));
  else
    printf("[WINDOW] %s\n", "Renderer initialized");
  return (0);
}

int	Win_destroy()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  return (0);
}

SDL_Window	*Win_getWindow()
{
  return (window);
}

SDL_Renderer	*Win_getRenderer()
{
  return (renderer);
}
