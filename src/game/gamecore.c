/*
** gamecore.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 16:03:00 2014 AHAMADA Samir
** Last update Sat Jun 21 01:05:37 2014 ENNEBATI Yassine
*/

#include <string.h>
#include "../core/renderer.h"
#include "mainmenu.h"
#include "handlers/sprite_handler.h"
#include "handlers/font_handler.h"
#include "handlers/sound_handler.h"
#include "gamecore.h"

t_mode		g_launcher;

Sint32		init_game()
{
  if (init_graphics())
    return (-1);
  load_sprites();
  load_fonts();
  load_sounds();
  redraw_context(&(SDL_Color){0, 0, 0, 255});
  return (0);
}

void		redraw_context(SDL_Color *c)
{
  SDL_Color	col;

  col = !c ? (SDL_Color){0, 0, 0, 255} : *c;
  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
  draw_sprite(CABINET_SPR, NULL);
}

void	game_loop()
{
  SDL_Event e;
  SDL_Scancode	s;

  memset(&e, 0, sizeof(e));
  draw_text("!!!!GAME!!!!", &(SDL_Point){190, 120}, COSMIC48_FNT,
	    &(SDL_Color){255, 255, 255, 255});
  while (g_launcher == &game_loop)
    {
      if (SDL_PollEvent(&e))
	if (e.type == SDL_QUIT)
	  g_launcher = NULL;
      if (e.type == SDL_KEYDOWN)
	{
	  s = e.key.keysym.scancode;
	  if (s == SDL_SCANCODE_ESCAPE)
	    {
	      g_launcher = &menu_game;
	      play_sfx(BLIPCANCEL_SFX);
	    }
	}

      SDL_RenderPresent(get_renderer());
      SDL_Delay(10);
    }
}

void	destroy_game()
{
  free_sounds();
  free_fonts();
  free_sprites();
  destroy_graphics();
}
