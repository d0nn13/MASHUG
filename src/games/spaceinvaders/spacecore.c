/*
** spacecore.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:00:29 2014 ENNEBATI Yassine
*/

#include <string.h>
#include "../../core/renderer.h"
#include "../../core/options.h"
#include "../../core/input.h"
#include "../../core/handlers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "spacespritesheet.h"
#include "spacemenu.h"
#include "objects/ship_callback.h"

#include "spacecore.h"

static t_spaceship	*ship;

static Uint8	process_events()
{
  SDL_Event	e;

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
    if (e.key.keysym.scancode == get_input(RETURN_INP)->code)
    {
      play_sfx(get_common_sfx(BLIPCANCEL_SFX));
      set_launcher(&space_menu);
    }
  }
  return (0);
}

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
  SDL_Point const	orig = {190, 120};

  Uint32		ti;
  Uint32		to;
  Uint32 const		t = (1000 / get_option_value(GAME_FPS_OPT));

  ship = get_spaceship();
  draw_text("!!!!GAME!!!!", &orig, get_common_font(COSMIC48_FNT), NULL);
  while (get_launcher() == &space_loop)
  {
    ti = SDL_GetTicks();
    if (process_events())
      break;
    space_redraw_context(NULL);
    ship->move(ship);
    ship->display(ship);
    SDL_RenderPresent(get_renderer());
    to = SDL_GetTicks() - ti;
    SDL_LogVerbose(0, "%d", to);
    if (to < t)
      SDL_Delay(t - to);
  }
}

