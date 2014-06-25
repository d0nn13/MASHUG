/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Tue Jun 24 18:33:06 2014 AHAMADA Samir
*/

/**
 *	@file	spaceinvaders.c
 *	@brief	Main game file
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include "version.h"
#include "log.h"
#include "window.h"
#include "renderer.h"
#include "graphics.h"
#include "audio.h"
#include "../game/gamecore.h"
#include "../game/mainmenu.h"
#include "spaceinvaders.h"

Sint32	core_init()
{
  printf("\nS P A C E  I N V A D E R S\n==========================\n");
  if ((SDL_Init(0) != 0))
    {
      SDL_LogError(0, "Couldn't initialize SDL : %s",
		   SDL_GetError());
      return (1);
    }
  print_versions();
  log_init();
  SDL_Log("Engine started, welcome aboard!");
  if (window_init() || renderer_init() || graphics_init() || audio_init())
    return (-1);
  return (0);
}

Sint32	core_destroy()
{
  audio_destroy();
  graphics_destroy();
  renderer_destroy();
  window_destroy();
  SDL_Log("Now everything is shut down, see ya!");
  return (0);
}

Sint32	main(int ac, char **av)
{
  (void)ac;
  chdir(dirname(*av));
  chdir("..");

  if (core_init() || game_init())
    return (EXIT_FAILURE);
  g_launcher = &menu_game;
  while (g_launcher)
    {
      redraw_context(NULL);
      g_launcher();
    }
  game_destroy();
  core_destroy();
  atexit(SDL_Quit);
  return (EXIT_SUCCESS);
}
