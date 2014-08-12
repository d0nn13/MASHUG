/*
** spaceinvaders.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Fri Aug 08 22:22:31 2014 Samir Ahamada
** Last update Sun Aug 10 03:51:58 2014 ENNEBATI Yassine
*/

#include <SDL2/SDL_stdinc.h>
#include "../../core/log.h"
#include "../../core/launcher.h"
#include "spacespritesheet.h"
#include "spacemenu.h"
#include "objects/ship.h"
#include "objects/alien.h"
#include "objects/block.h"
#include "../mainmenu.h"

#include "spaceinvaders.h"

static	Uint8 loaded = 0;

static void	spaceobjects_init()
{
  spaceship_init();
  spacealiens_init();
  spaceblock_init();
}

static void	spaceobjects_destroy()
{
  spaceblock_destroy();
  spacealiens_destroy();
  spaceship_destroy();
}

void 	space_init()
{
  if (!loaded)
  {
    load_space_spritesheet();
    spaceobjects_init();
    loaded = 1;
  }
  else
    SDL_LogWarn(APP_LCAT,
		   "Tried to load an already loaded Space Invaders game");
  set_launcher(&space_menu);
}

void	space_destroy()
{
  if (loaded)
  {
    spaceobjects_destroy();
    free_space_spritesheet();
    loaded = 0;
  }
  else
    SDL_LogWarn(APP_LCAT,
		   "Tried to unload an non-loaded Space Invaders game");
  set_launcher(&main_menu);
}
