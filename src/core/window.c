/*
** window.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 21 11:38:31 2014 AHAMADA Samir
** Last update Tue Jun 24 18:14:37 2014 AHAMADA Samir
*/

/**
 *	@file	window.c
 *	@brief	Window handling engine
 */

#include <SDL2/SDL.h>
#include "log.h"

#include "window.h"

static SDL_Window	*window = NULL;

Sint32	window_init()
{
  const char	*window_title = "-=  S P A C E  I N V A D E R S  =-";

  if (SDL_InitSubSystem(SDL_INIT_VIDEO))
    {
      SDL_LogError(VID_LCAT, "Couldn't initialize video : %s", SDL_GetError());
      return (-1);
    }
  window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H,
			    SDL_WINDOW_HIDDEN);
  if (!window)
    {
      SDL_LogError(VID_LCAT, "Couldn't initialize window : %s", SDL_GetError());
      return (-1);
    }
  SDL_LogInfo(VID_LCAT, "Window initialization done");
  return (0);
}

void	window_destroy()
{
  SDL_DestroyWindow(window);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  SDL_LogInfo(VID_LCAT, "Window destroyed");
}

SDL_Window	*get_window()
{
  return (window);
}
