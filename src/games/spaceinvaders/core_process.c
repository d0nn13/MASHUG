/*
** core_process.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:17 2014 ENNEBATI Yassine
** Last update Fri Sep 26 11:05:06 2014 Emmanuel Atse
*/

#include <string.h>
#include "../../core/input.h"
#include "../../core/launcher.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "gameover.h"
#include "objects/alien.h"
#include "objects/alien_callback.h"
#include "menu.h"
#include "context.h"

#include "core_process.h"

static void	process_collisions(t_spaceobjects *o)
{
  Uint8		i;
  int		has_aliens;

  o->rocket->collide(o->rocket);
  for (i = 0; i < NB_ALIENS_ROCKETS; ++i)
    o->alien_rockets[i]->collide(o->alien_rockets[i], i);
  has_aliens = 0;
  for (i = 0; i < NB_ALIENS_COL; ++i)
    if (o->aliens->columns[i])
      {
	has_aliens = 1;
	break ;
      }
  if (!has_aliens)
    {
      ++get_spacecontext()->wave;
      spacealiens_destroy(&o->aliens);
      o->aliens = spacealiens_init();
    }
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
    else if (e.key.keysym.scancode == get_input(GAMEOVER_TEST_INP)->code)
    {
      set_launcher(&space_gameover);
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
