/*
** gameover.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Sep  7 18:58:23 2014 ENNEBATI Yassine
** Last update Sun Sep  7 19:53:47 2014 ENNEBATI Yassine
*/

#include "../../core/renderer.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../../core/launcher.h"
#include "../../core/input.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "menu.h"

#include "gameover.h"

/* >25 lines */
static Uint8	process_events(t_letter *name, Uint8 *idx)
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
    if (e.key.keysym.scancode == get_input(DOWN_INP)->code)
      name[*idx].letter += name[*idx].letter < 'Z' ? 1 : -25;
    if (e.key.keysym.scancode == get_input(UP_INP)->code)
      name[*idx].letter -= name[*idx].letter > 'A' ? 1 : -25;
  }
  return (0);
}

static void		display_name(t_letter *name, Uint8 idx)
{
  SDL_Point		orig;
  SDL_Color const	red = {255, 0, 0, 0};
  char			buf[2];
  Uint8			i;

  renderer_clear(NULL);
  memset(buf, 0, 2);
  i = 0;
  orig = point_factory(330, 130);
  draw_text("GAME OVER", &orig, get_common_font(COSMIC24_FNT), &red);
  orig.y = 150;
  for (i = 0; i < NB_LETTER; ++i)
  {
    buf[0] = name[i].letter;
    draw_text(buf, &orig, get_common_font(COSMIC24_FNT),
	      idx == i ? &(name[i].sel_color) : &name[i].uns_color);
    orig.x += 18;
  }
}

static void		name_init(t_letter *name)
{
  SDL_Color const	white = {152, 128, 208, 0};
  SDL_Color const	purple = {255, 255, 255, 0};
  Uint8			i;

  for (i = 0; i < NB_LETTER; ++i)
  {
    name[i].letter = 'A';
    name[i].sel_color = white;
    name[i].uns_color = purple;
  }
}

void			space_gameover()
{
  t_letter		name[NB_LETTER];
  Uint8			idx;

  idx = 0;
  name_init(name);
  display_name(name, idx);
  SDL_RenderPresent(get_renderer());
  while (get_launcher() == &space_gameover)
  {
    if (process_events(name, &idx))
      break;
  SDL_RenderPresent(get_renderer());
    display_name(name, idx);
  }
}
