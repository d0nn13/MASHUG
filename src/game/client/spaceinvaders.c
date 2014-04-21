/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Mon Apr 21 17:10:44 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "../../external/libmy/my.h"
#include "../../core/log.h"
#include "../../core/gfx/window.h"

void	Game_loop();

int	main()
{
  printf("%s", "S P A C E  I N V A D E R S\n==========================\n\n");
  if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0))
    return (print_error("Space Invaders", "Couldn't initialize SDL", SDL_GetError()));
  else
    print_log("Space Invaders", "Engine started, welcome aboard!", NULL);
  Win_init();

  Game_loop();

  Win_destroy();
  print_log("Space Invaders", "Now everything is shut down, see ya!", NULL);
  atexit(SDL_Quit);
  return (0);
}

void	Game_loop()
{
  SDL_Event e;
  while (1)
    {
      if (SDL_PollEvent(&e))
	if (e.type == SDL_QUIT)
	  break;
      SDL_Delay(10);
    }
}
