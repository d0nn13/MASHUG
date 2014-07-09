/*
** gamecore.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 16:03:00 2014 AHAMADA Samir
** Last update Wed Jul  9 13:28:18 2014 ENNEBATI Yassine
*/

#include <string.h>
#include "../../core/renderer.h"
#include "../../core/handlers.h"
#include "../common/sprites.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "menu.h"

#include "gamecore.h"

t_mode		g_launcher;

Sint32		game_init()
{
  load_common_sprites();
  load_common_fonts();
  load_common_sfx();
  return (0);
}

/* TODO: ptr_chk() on c */
void		redraw_context(const SDL_Color *c)
{
  const SDL_Color	black = {0, 0, 0, 255};
  SDL_Color		col;

  col = !c ? black : *c;
  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
  draw_sprite(get_common_sprite(CABINET_SPR), NULL);
}

void			game_loop()
{
  const SDL_Color	white = {255, 255, 255, 255};
  const SDL_Point	orig = {190, 120};
  SDL_Event		e;
  SDL_Scancode		s;

  memset(&e, 0, sizeof(e));
  draw_text("!!!!GAME!!!!", &orig, get_common_font(COSMIC48_FNT),
	    &white);
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
	      play_sfx(get_common_sfx(BLIPCANCEL_SFX));
	    }
	}
      SDL_RenderPresent(get_renderer());
      SDL_Delay(10);
    }
}

void	game_destroy()
{
  free_common_sfx();
  free_common_fonts();
  free_common_sprites();
}
