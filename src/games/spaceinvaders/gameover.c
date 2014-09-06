/*
** spacegameover.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sat Sep  6 12:32:02 2014 ENNEBATI Yassine
** Last update Sat Sep  6 13:21:02 2014 ENNEBATI Yassine
*/

#include "../../core/renderer.h"
#include "../../core/helpers.h"
#include "../../core/handlers.h"
#include "../../core/launcher.h"
#include "../../core/input.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "menu.h"

#include "spacegameover.h"

static Uint8	process_events()
{
  SDL_Event	e;

  if (!SDL_WaitEvent(&e))
    return (0);
  if (e.type == SDL_QUIT)
  {
    set_launcher(NULL);
    return (1);
  }
  if (e.type == SDL_KEYDOWN)
  {
    if (e.key.keysym.scancode == get_input(RETURN_INP)->code)
    {
      play_sfx(get_common_sfx(BLIPCANCEL_SFX));
      set_launcher(&space_menu);
      return (1);
    }
  }
  return (0);
}

void			space_gameover()
{
  SDL_Point		orig;
  SDL_Color const	red = {255, 0, 0, 0};

  orig = point_factory(330, 130);
  renderer_clear(NULL);
  draw_text("GAME OVER", &orig, get_common_font(COSMIC24_FNT), &red);
  SDL_RenderPresent(get_renderer());
  while (get_launcher() == &space_gameover)
  {
    if (process_events())
      break;
  }
}
