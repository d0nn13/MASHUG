/*
** mashug.c for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Jul 13 10:41:09 2014 Samir Ahamada
** Last update Mon Jul 14 16:07:11 2014 ENNEBATI Yassine
*/

/**
 *	@file	mashug.c
 *	@brief	Main game file
 */
/* TODO: Remove XML tests before merge */

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
#ifdef XML_TESTS
# include "handlers.h"
#endif

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

#ifdef XML_TESTS
void xml_tests()
{
  t_hiscoreholder *hiscores = 0;
  Uint8 count, i;
  SDL_Log("XML Tests");
  count = xml_parse("media/hiscores.xml", &xml_hiscore_callback, NULL);
  if (!count)
  {
    SDL_LogError(XML_LCAT, "XML Parse failed");
    return ;
  }
  SDL_LogInfo(XML_LCAT, "Count = %d", count);
  hiscores = mem_alloc(count * sizeof(t_hiscoreholder));
  memset(hiscores, 0, count * sizeof(t_hiscoreholder));
  if (!ptr_chk(hiscores, "hiscores", APP_LCAT, "xml_tests"))
    return ;
  xml_parse("media/hiscores.xml", &xml_hiscore_callback, hiscores);
  for (i = 0; i < count; ++i)
  {
    SDL_LogInfo(XML_LCAT, "Nickname[%d]: %s", i, hiscores[i].nickname);
    SDL_LogInfo(XML_LCAT, "Score[%d]: %d", i, hiscores[i].score);
    SDL_LogInfo(XML_LCAT, "Date[%d]: %d", i, hiscores[i].date);
  }
  mem_free(hiscores);
}
#endif

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
#ifdef XML_TESTS
  xml_tests();
#endif
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
  {
    g_launcher();
  }
  space_destroy();
  core_destroy();
  SDL_Log("Alloc vs Free status : %d", mem_get_nb_allocs());
  atexit(SDL_Quit);
  return (EXIT_SUCCESS);
}
