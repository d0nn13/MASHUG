/*
** core_process.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Fri Sep 26 02:39:39 2014 Emmanuel Atse
*/

#include <string.h>
#include "../../core/input.h"
#include "../../core/launcher.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "objects/alien.h"
#include "objects/alien_callback.h"
#include "menu.h"

#include "core_process.h"

static void	process_collisions(t_spaceobjects *o)
{
  Uint8		i;

  o->rocket->collide(o->rocket);
  for (i = 0; i < NB_ALIENS_ROCKETS; ++i)
    o->alien_rockets[i]->collide(o->alien_rockets[i], i);
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
  Uint8	i;

  o->ship->move(o->ship);
  o->ufo->move(o->ufo);
  o->aliens->move(o->aliens);
  input_update();
  if (!o->rocket->state == FIRED && get_input(FIRE_INP)->state)
    o->ship->fire(o->ship, o->rocket);
  o->aliens->fire(o->aliens, o->alien_rockets);
  process_collisions(o);
  o->ship->display(o->ship);
  o->rocket->display(o->rocket);
  for (i = 0; i < NB_ALIENS_ROCKETS; ++i)
    o->alien_rockets[i]->display(o->alien_rockets[i], i);
  ((t_spaceblock *)o->blocks->data)->display(o->blocks);
  o->aliens->display(o->aliens);
  o->ufo->display(o->ufo);
}
