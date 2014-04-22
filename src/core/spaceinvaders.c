/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Wed Apr 23 01:43:09 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "core.h"
#include "gfx/display.h"
#include "spaceinvaders.h"

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
  uInt8	run;
  SDL_Event e;

  run = 1;
  while (run)
    {
      if (SDL_PollEvent(&e))
	if (e.type == SDL_QUIT)
	  run = 0;;

      SDL_RenderCopy(Dspl_getRender(), Dspl_getTexture(), NULL, NULL);
      SDL_RenderPresent(Dspl_getRender());
      SDL_Delay(10);
    }
}
