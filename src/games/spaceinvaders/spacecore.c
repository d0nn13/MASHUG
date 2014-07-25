/*
** spacecore.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Wed Jul 23 10:46:54 2014 Emmanuel Atse
*/

#include <string.h>
#include "../../core/renderer.h"
#include "../../core/handlers.h"
#include "../common/sprites.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spacespritesheet.h"
#include "spacemenu.h"
#include "spacecore.h"

t_mode 	g_launcher;

Sint32 	space_init()
{
  load_space_spritesheet();
  load_common_fonts();
  load_common_sfx();
  return (0);
}

void			redraw_context(SDL_Color const *c)
{
  SDL_Color const	black = {0, 0, 0, 255};
  SDL_Color		col;
  t_spritesheet const	*ss;

  col = !c ? black : *c;
  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
  ss = get_space_spritesheet();
  draw_sprite(ss, get_sprite(ss, CABINET_SPR), NULL);
}

void			space_loop()
{
  SDL_Color const	white = {255, 255, 255, 255};
  SDL_Point const	orig = {190, 120};
  SDL_Event		e;
  SDL_Scancode		s;

  memset(&e, 0, sizeof(e));
  draw_text("!!!!GAME!!!!", &orig, get_common_font(COSMIC48_FNT),
	    &white);
  while (g_launcher == &space_loop)
  {
    if (SDL_PollEvent(&e))
      if (e.type == SDL_QUIT)
	g_launcher = NULL;
    if (e.type == SDL_KEYDOWN)
    {
      s = e.key.keysym.scancode;
      if (s == SDL_SCANCODE_ESCAPE)
      {
	g_launcher = &space_menu;
	play_sfx(get_common_sfx(BLIPCANCEL_SFX));
      }
    }
    SDL_RenderPresent(get_renderer());
    SDL_Delay(10);
  }
}

void	space_destroy()
{
  free_common_sfx();
  free_common_fonts();
  free_space_spritesheet();
}
