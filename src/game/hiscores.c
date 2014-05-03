/*
** hiscores.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat May  3 20:33:34 2014 AHAMADA Samir
** Last update Sat May  3 21:23:52 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "font_handler.h"

#if defined __MACH__
# define	SCOREFILE	"/Users/`whoami`/.spaceinvaders.hiscores"
#elif defined __linux__
# define	SCOREFILE	"/home/`whoami`/.spaceinvaders.hiscores"
#else
# define	SCOREFILE	"./.spaceinvaders.hiscores"
#endif

void	hiscores()
{
  draw_text("HISCORES", &(SDL_Point){240,0}, COSMIC48_FNT,
	    &(SDL_Color){255, 255, 255, 255});
}
Sint32	load_hiscores();
Sint32	save_hiscores();


