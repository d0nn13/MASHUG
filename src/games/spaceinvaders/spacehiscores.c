/*
** spacehiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:55:21 2014 Emmanuel Atse
*/

#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/handlers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "spacesprites.h"
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
  SDL_Point const	orig = {240, 120};
  SDL_Color const	white = {255, 255, 255, 255};

  renderer_clear(NULL);
  draw_text("HISCORES", &orig, get_common_font(COSMIC48_FNT),
	    &white);
  draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
  while (get_launcher() == &hiscores)
  {
    SDL_RenderPresent(get_renderer());
    if (SDL_WaitEvent(&e))
      if (e.type == SDL_QUIT)
      {
	space_destroy();
	set_launcher(NULL);
      }
    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.scancode == get_input(RETURN_INP)->code)
      {
	play_sfx(get_common_sfx(BLIPCANCEL_SFX));
	set_launcher(&space_menu);
      }
    }
  }
}

Sint32	load_hiscores();

Sint32	save_hiscores();
