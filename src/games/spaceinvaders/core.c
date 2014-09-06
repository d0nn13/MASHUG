/*
** core.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:55:33 2014 Emmanuel Atse
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

static SDL_Rect	const	space_bounds = {141, 120, 486, 432};
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
  set_launcher(&space_loop);
}

void	spacecore_destroy()
{
  spacealiens_destroy(&objects.aliens);
  spaceblocks_destroy(&objects.blocks);
  spacerocket_destroy(&objects.rocket);
  spaceship_destroy(&objects.ship);
}

void			space_loop()
{
  Uint32		ti;
  Uint32		to;
  Uint32 const		t = (1000 / get_option_value(FRAMERATE_OPT));

  while (get_launcher() == &space_loop)
  {
    ti = SDL_GetTicks();
    renderer_clear(NULL);
    display_hud();
    if (space_process_events())
      break;
    space_process_objects(&objects);
    draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
    SDL_RenderPresent(get_renderer());
    to = SDL_GetTicks() - ti;
    if (to < t)
      SDL_Delay(t - to);
    SDL_LogVerbose(0, "%d", to);
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
