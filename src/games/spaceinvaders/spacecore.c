/*
** spacecore.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Sun Jul 27 15:18:10 2014 ENNEBATI Yassine
*/

#include <string.h>
#include "../../core/renderer.h"
#include "../../core/handlers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "spacespritesheet.h"
#include "spacemenu.h"

#include "spacecore.h"

static Uint8	space_process_events();

void			space_redraw_context(SDL_Color const *c)
{
  SDL_Color const	black = {0, 0, 0, 255};
  SDL_Color		col;

  col = !c ? black : *c;
  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
  draw_sprite(get_sprite(get_space_spritesheet(), CABINET_SPR), NULL);
}

void			space_loop()
{
  SDL_Color const	white = {255, 255, 255, 255};
  SDL_Point const	orig = {190, 120};

  draw_text("!!!!GAME!!!!", &orig, get_common_font(COSMIC48_FNT),
	    &white);
  while (get_launcher() == &space_loop)
  {
    SDL_RenderPresent(get_renderer());
    if (space_process_events())
      break;
    SDL_Delay(10);
  }
}

static Uint8	space_process_events()
{
  SDL_Event		e;
  SDL_Scancode		s;

  memset(&e, 0, sizeof(e));
  if (!SDL_PollEvent(&e))
    return (0);
  if (e.type == SDL_QUIT)
  {
    space_destroy();
    set_launcher(NULL);
    return (1);
  }
  else if (e.type == SDL_KEYDOWN)
  {
    s = e.key.keysym.scancode;
    if (s == SDL_SCANCODE_ESCAPE)
    {
      set_launcher(&space_menu);
      play_sfx(get_common_sfx(BLIPCANCEL_SFX));
    }
  }
  return (0);
}

