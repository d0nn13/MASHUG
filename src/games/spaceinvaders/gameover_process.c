/*
** gameover_process.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sat Sep 20 23:13:09 2014 ENNEBATI Yassine
** Last update Sat Sep 20 23:30:57 2014 ENNEBATI Yassine
*/

#include "../../core/handlers.h"
#include "../../core/input.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "menu.h"

#include "gameover.h"

#define	UP	1
#define	DOWN	2
#define	BUFF_SIZE 37

static char const	letters[BUFF_SIZE] = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

static void	change_letter(t_letter *name, Uint8 idx, Uint8 state)
{
  Sint8		i;

  i = 0;
  while (letters[i] != name[idx].letter)
    i++;
  if (state == DOWN)
  {
    if (i + 1 == BUFF_SIZE)
      i = -1;
    name[idx].letter = letters[++i];
  }
  else
  {
    if (i == 0)
      i = BUFF_SIZE;
    name[idx].letter = letters[--i];
  }
}

static Uint8	process_input(SDL_Event e, t_letter *name, Uint8 *idx)
{
  if (e.key.keysym.scancode == get_input(RETURN_INP)->code)
  {
    play_sfx(get_common_sfx(BLIPCANCEL_SFX));
    set_launcher(&space_menu);
    return (1);
  }
  if (e.key.keysym.scancode == get_input(RIGHT_INP)->code)
    *idx += *idx + 1 < NB_LETTER ? 1 : 0;
  if (e.key.keysym.scancode == get_input(LEFT_INP)->code)
    *idx -= *idx > 0 ? 1 : 0;
  if (e.key.keysym.scancode == get_input(UP_INP)->code)
    change_letter(name, *idx, UP);
  if (e.key.keysym.scancode == get_input(DOWN_INP)->code)
    change_letter(name, *idx, DOWN);
  return (0);
}

Uint8		gameover_process_events(t_letter *name, Uint8 *idx)
{
  SDL_Event	e;

  if (!SDL_WaitEvent(&e))
    return (0);
  if (e.type == SDL_QUIT)
  {
    space_destroy();
    set_launcher(NULL);
    return (1);
  }
  if (e.type == SDL_KEYDOWN)
    return (process_input(e, name, idx));
  return (0);
}
