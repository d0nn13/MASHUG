/*
** hiscores.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat May  3 20:33:34 2014 AHAMADA Samir
** Last update Fri Jun 27 17:43:09 2014 AHAMADA Samir
*/

#include <SDL2/SDL_render.h>
#include "../core/handlers.h"
#include "common/sprites.h"
#include "common/fonts.h"
#include "common/sfx.h"
#include "gamecore.h"
#include "mainmenu.h"

#include "hiscores.h"

#if defined __MACH__
# define	SCOREFILE	"/Users/`whoami`/.si_hiscores.xml"
#elif defined __linux__
# define	SCOREFILE	"/home/`whoami`/.si_hiscores.xml"
#else
# define	SCOREFILE	"./.si_hiscores.xml"
#endif

void		hiscores()
{
  SDL_Event	e;
  SDL_Scancode	s;

  draw_text("HISCORES", &(SDL_Point){240,120}, get_common_font(COSMIC48_FNT),
	    &(SDL_Color){255, 255, 255, 255});
  while (g_launcher == &hiscores)
    {
      if (SDL_WaitEvent(&e))
	if (e.type == SDL_QUIT)
	  g_launcher = NULL;
      if (e.type == SDL_KEYDOWN)
	{
	  s = e.key.keysym.scancode;
	  if (s == SDL_SCANCODE_ESCAPE)
	    {
	      g_launcher = &menu_game;
	      play_sfx(get_common_sfx(BLIPCANCEL_SFX));
	    }
	}
    }
}

Sint32	load_hiscores();
Sint32	save_hiscores();
