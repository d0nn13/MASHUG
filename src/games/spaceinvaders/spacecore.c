/*
** spacecore.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Wed Sep  3 14:55:33 2014 Emmanuel Atse
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
#include "spacesprites.h"
#include "spacemenu.h"
#include "objects/ship_callback.h"
#include "objects/rocket_callback.h"
#include "objects/alien_callback.h"
#include "objects/block_callback.h"

#include "spacecore.h"

static SDL_Rect	const	space_bounds = {141, 120, 486, 432};
static t_spaceship	*ship = NULL;
static t_spacerocket	*rocket = NULL;
static t_singlelist	*aliens = NULL;
static t_singlelist	*blocks = NULL;

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
      return (1);
    }
  }
  return (0);
}

static void	process_collisions()
{
  rocket->collide(rocket);
}

static void	process_objects()
{
  ship->move(ship);
  input_update();
  if (!rocket->state == FIRED && get_input(FIRE_INP)->state)
    ship->fire(ship, rocket);
  process_collisions();
  ship->display(ship);
  rocket->display(rocket);
  ((t_spaceblock *)blocks->data)->display(blocks);
  ((t_spacealien *)aliens->data)->display(aliens);
}

void			space_loop()
{
  Uint32		ti;
  Uint32		to;
  Uint32 const		t = (1000 / get_option_value(FRAMERATE_OPT));

  ship = get_spaceship();
  rocket = get_spacerocket();
  aliens = get_spacealiens();
  blocks = get_spaceblocks();
  while (get_launcher() == &space_loop)
  {
    ti = SDL_GetTicks();
    renderer_clear(NULL);
    if (process_events())
      break;
    process_objects();
    draw_sprite(get_sprite(get_space_sprites(), CABINET_SPR), NULL);
    SDL_RenderPresent(get_renderer());
    to = SDL_GetTicks() - ti;
    if (to < t)
      SDL_Delay(t - to);
    SDL_LogVerbose(0, "%d", to);
  }
}

SDL_Rect const	*get_spacebounds()
{
  return (&space_bounds);
}
