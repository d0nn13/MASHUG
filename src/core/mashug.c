/*
** mashug.c for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Jul 13 10:41:09 2014 Samir Ahamada
** Last update Sat Jul 26 15:53:56 2014 ENNEBATI Yassine
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
#include "options.h"
#include "clioptions.h"
#include "log.h"
#include "window.h"
#include "renderer.h"
#include "graphics.h"
#include "audio.h"
#include "input.h"
#include "launcher.h"
#include "../games/common/common.h"
#include "../games/mainmenu.h"

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
    return (-1);
  }
  print_versions();
  log_init();
  set_options_from_cli(argc, argv);
  log_set_all_priority(get_option_value(LOG_PRIO_OPT));
  if (window_init() || renderer_init() || graphics_init() || audio_init())
    return (-2);
  SDL_SetEventFilter(key_filter, NULL);
  SDL_Log("Engine started, welcome aboard!");
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
  if (core_init(argc, argv) || common_init())
    return (EXIT_FAILURE);
  set_launcher(&main_menu);
  while (get_launcher())
  {
    get_launcher()();
  }
  common_destroy();
  core_destroy();
  SDL_LogDebug(APP_LCAT, "Alloc vs Free status : %d", mem_get_nb_allocs());
  atexit(SDL_Quit);
  return (EXIT_SUCCESS);
}
