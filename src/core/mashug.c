/*
** mashug.c for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Jul 13 10:41:09 2014 Samir Ahamada
** Last update Tue Jul 15 12:32:09 2014 ENNEBATI Yassine
*/

/**
 *	@file	mashug.c
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
#include "../games/mainmenu.h"
#include "../games/spaceinvaders/spacecore.h"

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
  printf("\nM A S H U G: Multiple Arcade SHoot'em Up Games\n");
  printf("==============================================\n");
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
  chdir(dirname(*argv));
  chdir("..");
  if (core_init(argc, argv) || space_init())
    return (EXIT_FAILURE);
  g_launcher = &main_menu;
  while (g_launcher)
    g_launcher();
  space_destroy();
  core_destroy();
  SDL_Log("Alloc vs Free status : %d", mem_get_nb_allocs());
  atexit(SDL_Quit);
  return (EXIT_SUCCESS);
}
