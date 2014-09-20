/*
** core.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Sun Sep  7 16:11:30 2014 FOFANA Ibrahim
*/

#include "../../core/renderer.h"
#include "../../core/options.h"
#include "../../core/handlers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "sprites.h"
#include "menu.h"
#include "core_process.h"

#include "core.h"

#ifndef PROCESS_PERIOD_MS
# define PROCESS_PERIOD_MS	5
#endif
#define RENDER_PERIOD_MS	((Uint8)(1000 / get_option_value(FRAMERATE_OPT)))

static SDL_Rect	const	space_bounds = {139, 147, 567, 499};
static t_spaceobjects	objects;

static void	display_hud()
{
}

void	spacecore_init()
{
  objects.ship = spaceship_init();
  objects.rocket = spacerocket_init();
  objects.blocks = spaceblocks_init();
  objects.aliens = spacealiens_init();
  objects.ufo = spaceufo_init();
  set_launcher(&space_loop);
}

void	spacecore_destroy()
{
  spaceufo_destroy(&objects.ufo);
  spacealiens_destroy(&objects.aliens);
  spaceblocks_destroy(&objects.blocks);
  spacerocket_destroy(&objects.rocket);
  spaceship_destroy(&objects.ship);
}

void			space_loop()
{
  Uint32		t_old;

  t_old = 0;
  while (get_launcher() == &space_loop)
  {
    renderer_clear(NULL);
    display_hud();
    if (space_process_events())
      break;
    space_process_objects(&objects);
    draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
    SDL_Delay(PROCESS_PERIOD_MS);
    if (SDL_GetTicks() - t_old < RENDER_PERIOD_MS)
      continue;
    SDL_RenderPresent(get_renderer());
    t_old = SDL_GetTicks();
  }
}

t_spaceobjects	*get_spaceobjects()
{
  return (&objects);
}

SDL_Rect const	*get_spacebounds()
{
  return (&space_bounds);
}
