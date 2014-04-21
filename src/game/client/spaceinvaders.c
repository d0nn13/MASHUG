/*
** spaceinvaders.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:52:48 2014 AHAMADA Samir
** Last update Mon Apr 21 12:41:17 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include "../../external/libmy/my.h"
#include "../../core/gfx/window.h"

void	Game_loop();

int	main()
{
  printf("%s", "S P A C E  I N V A D E R S\n==========================\n\n");
  SDL_Init(SDL_INIT_VIDEO);
  Win_init();
  Game_loop();
  Win_destroy();

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
    }
}
