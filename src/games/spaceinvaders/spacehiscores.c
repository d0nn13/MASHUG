/*
** spacehiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Sun Jul 27 15:17:42 2014 ENNEBATI Yassine
*/

#include <SDL2/SDL_render.h>
#include "../../core/handlers.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spacecore.h"
#include "spacemenu.h"

#include "spacehiscores.h"

#if defined __MACH__
# define SCOREFILE	"/Users/`whoami`/.si_hiscores.xml"
#elif defined __linux__
# define SCOREFILE	"/home/`whoami`/.si_hiscores.xml"
#else
# define SCOREFILE	"./.si_hiscores.xml"
#endif

void			hiscores()
{
  SDL_Event		e;
  SDL_Scancode		s;
  SDL_Point const	orig = {240, 120};
  SDL_Color const	white = {255, 255, 255, 255};

  draw_text("HISCORES", &orig, get_common_font(COSMIC48_FNT),
	    &white);
  while (g_launcher == &hiscores)
  {
    if (SDL_WaitEvent(&e))
      if (e.type == SDL_QUIT)
      {
	space_destroy();
	g_launcher = NULL;
      }
    if (e.type == SDL_KEYDOWN)
    {
      s = e.key.keysym.scancode;
      if (s == SDL_SCANCODE_ESCAPE)
      {
	g_launcher = &space_menu;
	play_sfx(get_common_sfx(BLIPCANCEL_SFX));
      }
    }
  }
}

Sint32	load_hiscores();
Sint32	save_hiscores();
