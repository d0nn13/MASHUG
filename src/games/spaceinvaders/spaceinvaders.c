/*
** spaceinvaders.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Fri Aug 08 22:22:31 2014 Samir Ahamada
** Last update Sun Aug 10 01:32:11 2014 ENNEBATI Yassine
*/

#include <SDL2/SDL_stdinc.h>
#include "../../core/log.h"
#include "../../core/launcher.h"
#include "spacespritesheet.h"
#include "spacemenu.h"
#include "objects/ship/ship.h"
#include "../mainmenu.h"

#include "spaceinvaders.h"

static	Uint8 loaded = 0;

void	space_init_objects()
{
  space_init_ship();
}

void 	space_init()
{
  if (!loaded)
  {
    load_space_spritesheet();
    loaded = 1;
  }
  else
    SDL_LogWarn(APP_LCAT,
		   "Tried to load an already loaded Space Invaders game");
  space_init_objects();
  set_launcher(&space_menu);
}

void	space_destroy()
{
  if (loaded)
  {
    free_space_spritesheet();
    loaded = 0;
  }
  else
    SDL_LogWarn(APP_LCAT,
		   "Tried to unload an non-loaded Space Invaders game");
  set_launcher(&main_menu);
}

Uint8	space_is_loaded()
{
  return (loaded);
}
