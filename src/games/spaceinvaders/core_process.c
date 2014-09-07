/*
** core_process.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Sat Sep  6 17:16:48 2014 ENNEBATI Yassine
*/

#include <string.h>
#include "../../core/input.h"
#include "../../core/launcher.h"
#include "../../core/handlers.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "menu.h"

#include "core_process.h"

static void	process_collisions(t_spaceobjects *o)
{
  o->rocket->collide(o->rocket);
}

Uint8		space_process_events()
{
  SDL_Event	e;

  memset(&e, 0, sizeof(e));
  if (!SDL_PollEvent(&e))
    return (0);
  if (e.type == SDL_QUIT)
  {
    spacecore_destroy();
    space_destroy();
    set_launcher(NULL);
    return (1);
  }
  else if (e.type == SDL_KEYDOWN)
  {
    if (e.key.keysym.scancode == get_input(RETURN_INP)->code)
    {
      play_sfx(get_common_sfx(BLIPCANCEL_SFX));
      spacecore_destroy();
      set_launcher(&space_menu);
      return (1);
    }
  }
  return (0);
}

void	space_process_objects(t_spaceobjects *o)
{
  o->ship->move(o->ship);
  o->ufo->move(o->ufo);
  input_update();
  if (!o->rocket->state == FIRED && get_input(FIRE_INP)->state)
    o->ship->fire(o->ship, o->rocket);
  process_collisions(o);
  o->ship->display(o->ship);
  o->rocket->display(o->rocket);
  ((t_spaceblock *)o->blocks->data)->display(o->blocks);
  ((t_spacealien *)o->aliens->data)->display(o->aliens);
  o->ufo->display(o->ufo);
}
