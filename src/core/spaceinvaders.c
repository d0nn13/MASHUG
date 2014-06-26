/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Thu Jul  3 14:17:14 2014 AHAMADA Samir
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
#include "../base/memory.h"
#include "version.h"
#include "clioptions.h"
#include "log.h"
#include "window.h"
#include "renderer.h"
#include "graphics.h"
#include "audio.h"
#include "../game/gamecore.h"
#include "../game/mainmenu.h"

/**
 *	@brief	Initializes all engine modules
 *
 *	@return	0 if all initializations are succeded
 *	@return -1 if a module initialization failed
 */
static Sint32	core_init(Sint32 argc, char **argv);

/**
 *	@brief	Destroys all engine modules
 *
 *	@return	0
 */
static Sint32	core_destroy();

static Sint32	core_init(Sint32 argc, char **argv)
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
  set_options_from_cli(argc, argv);
  if (window_init() || renderer_init() || graphics_init() || audio_init())
    return (-1);
  return (0);
}

static Sint32	core_destroy()
{
  audio_destroy();
  graphics_destroy();
  renderer_destroy();
  window_destroy();
  SDL_Log("Now everything is shut down, see ya!");
  return (0);
}

Sint32	main(int argc, char **argv)
{
  (void)argc;
  chdir(dirname(*argv));
  chdir("..");

  if (core_init(argc, argv) || game_init())
    return (EXIT_FAILURE);
  g_launcher = &menu_game;
  while (g_launcher)
    {
      redraw_context(NULL);
      g_launcher();
    }
  game_destroy();
  core_destroy();
  SDL_Log("Alloc vs Free status : %d", get_nb_allocs());
  atexit(SDL_Quit);
  return (EXIT_SUCCESS);
}
