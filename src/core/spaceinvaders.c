/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Sat May  3 22:15:26 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "version.h"
#include "log.h"
#include "window.h"
#include "renderer.h"
#include "audio.h"
#include "../game/gamecore.h"

Sint32	init_core()
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
  if (window_init() || renderer_init() || audio_init())
    return (-1);
  return (0);
}

void	game_loop(void (*launch)())
{
  Uint8	run;
  SDL_Event e;

  run = 1;
  SDL_SetRenderDrawColor(get_renderer(), 0, 0, 0, 255);	//* Temporarily clearing display for menu test
  SDL_RenderClear(get_renderer());			//*
  while (run)
    {
      if (SDL_PollEvent(&e))
	if (e.type == SDL_QUIT)
	  run = 0;
      launch();
      SDL_RenderPresent(get_renderer());
      SDL_Delay(10);
    }
}

Sint32	destroy_core()
{
  audio_destroy();
  renderer_destroy();
  window_destroy();
  SDL_Log("Now everything is shut down, see ya!");
  return (0);
}

Sint32	main()
{
  mode	m;

  if (init_core())
    return (-1);
  init_game();
  if ((m = menu_game()))
    game_loop(m);
  else
    SDL_LogError(0, "Null game mode callback !!!");
  destroy_game();
  destroy_core();
  atexit(SDL_Quit);
  return (0);
}

