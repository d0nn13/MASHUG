/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Tue Apr 22 02:08:40 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "../../core/core.h"

void	Game_loop();

int	main()
{
if (Core_init())
  return (1);
  Game_loop();
  Core_destroy();
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
