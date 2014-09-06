/*
** spaceinvaders.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Fri Aug 08 22:22:31 2014 Samir Ahamada
** Last update Wed Sep  3 14:53:58 2014 Emmanuel Atse
*/

#include <SDL2/SDL_stdinc.h>
#include "../../core/log.h"
#include "../../core/launcher.h"
#include "spacesprites.h"
#include "spacemenu.h"
#include "objects/ship.h"
#include "objects/rocket.h"
#include "objects/alien.h"
#include "objects/block.h"
#include "../mainmenu.h"

#include "spaceinvaders.h"

static	Uint8 loaded = 0;

static Uint8	spaceobjects_init()
{
  spaceship_init();
  spacerocket_init();
  spacealiens_init();
  spaceblock_init();
  return (0);
}

static void	spaceobjects_destroy()
{
  spaceblock_destroy();
  spacealiens_destroy();
  spacerocket_destroy();
  spaceship_destroy();
}

void 	space_init()
{
  if (loaded)
    SDL_LogWarn(APP_LCAT,
		"Tried to load an already loaded Space Invaders game");
  else
  {
    if (spacesprites_init() || spaceobjects_init())
    {
      SDL_LogCritical(APP_LCAT, "Space Invaders initialisation failed");
      set_launcher(&main_menu);
      return ;
    }
    else
      loaded = 1;
  }
  set_launcher(&space_menu);
}

void	space_destroy()
{
  if (!loaded)
    SDL_LogWarn(APP_LCAT,
		"Tried to unload an non-loaded Space Invaders game");
  else
  {
    spaceobjects_destroy();
    spacesprites_destroy();
    loaded = 0;
  }
  set_launcher(&main_menu);
}
