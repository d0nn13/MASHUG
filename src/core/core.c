/*
** core.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Apr 22 01:44:43 2014 AHAMADA Samir
** Last update Tue Apr 22 11:06:38 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_log.h>
#include "version.h"
#include "log.h"
#include "gfx/display.h"
#include "core.h"

int	Core_init()
{
  printf("%s", "S P A C E  I N V A D E R S\n==========================\n");
  if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0))
    {
      SDL_LogError(0, "Couldn't initialize SDL : %s",
		   SDL_GetError());
      return (1);
    }
  print_versions();
  Log_init();
  SDL_Log("Engine started, welcome aboard!");
  if (Dspl_init())
    return (1);
  return (0);
}

int	Core_destroy()
{
  Dspl_destroy();
  SDL_Log("Now everything is shut down, see ya!");
  return (0);
}

