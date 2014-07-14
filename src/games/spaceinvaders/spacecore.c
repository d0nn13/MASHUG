/*
** spacecore.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
*/

#include <string.h>
#include "../../core/renderer.h"
#include "../../core/handlers.h"
#include "../common/sprites.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spacemenu.h"
#include "spacecore.h"

t_mode		g_launcher;

Sint32		space_init()
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

void			space_loop()
{
  const SDL_Color	white = {255, 255, 255, 255};
  const SDL_Point	orig = {190, 120};
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
  free_common_sprites();
}
