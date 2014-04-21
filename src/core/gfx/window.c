/*
** window.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 11:38:31 2014 AHAMADA Samir
** Last update Mon Apr 21 17:14:45 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <SDL2/SDL_error.h>
#include "window.h"
#include "../log.h"

static SDL_Window	*window = NULL;
static SDL_Renderer	*renderer = NULL;

int	Win_init()
{
  window = SDL_CreateWindow("-=  S P A C E  I N V A D E R S  =-", 100, 100,
			    WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
  if (!window)
    return (print_error("Window", "Couldn't initialize window",
			SDL_GetError()));
  else
    print_log("Window", "Window initialized", NULL);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
    return (print_error("Window", "Couldn't initialize renderer", SDL_GetError()));
  else
    print_log("Window", "Renderer initialized", NULL);
  return (0);
}

void	Win_destroy()
{
  SDL_DestroyWindow(window);
  print_log("Window", "Window destroyed", NULL);
  SDL_DestroyRenderer(renderer);
  print_log("Window", "Renderer destroyed", NULL);
}

SDL_Window	*Win_getWindow()
{
  return (window);
}

SDL_Renderer	*Win_getRenderer()
{
  return (renderer);
}
