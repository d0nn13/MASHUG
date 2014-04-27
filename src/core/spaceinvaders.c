/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Sun Apr 27 18:04:40 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "version.h"
#include "log.h"
#include "window.h"
#include "renderer.h"
#include "audio.h"
#include "../game/gamecore.h"

int	Core_init()
{
  printf("%s", "S P A C E  I N V A D E R S\n==========================\n");
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
    return (1);
  return (0);
}

int	Core_destroy()
{
  audio_destroy();
  renderer_destroy();
  window_destroy();
  SDL_Log("Now everything is shut down, see ya!");
  return (0);
}

void	Game_loop()
{
  Uint8	run;
  SDL_Event e;

  run = 1;
  while (run)
    {
      if (SDL_PollEvent(&e))
	if (e.type == SDL_QUIT)
	  run = 0;


      SDL_Delay(10);
    }
}

Sint32	main()
{
  if (Core_init())
    return (-1);
init_game();
  Game_loop();
destroy_game();
  Core_destroy();
  atexit(SDL_Quit);
  return (0);
}

