/*
** spacemenu.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:06:00 2014 ENNEBATI Yassine
** Last update Sat Aug 23 12:29:11 2014 ENNEBATI Yassine
*/

#include <SDL2/SDL.h>
#include "../../base/math.h"
#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "sprites.h"
#include "core.h"
#include "hiscores.h"

#include "menu.h"

/**
 *	Space menu entries enumeration
 */
typedef enum
{
  START_MEN,
  SCORE_MEN,
  NB_MEN
}	t_menuentries;

/**
 *	Space menu entries initialization
 */
static t_menuentry	entries[NB_MEN] =
{
  {
    "START",
    {325, 298},
    {152, 128, 208, 0},
    {255, 255, 255, 0},
    &space_loop,
    1
  },
  {
    "HISCORES",
    {289, 369},
    {152, 128, 208, 0},
    {255, 255, 255, 0},
    &spacehiscores,
    1
  }
};

static t_menuentries	item = START_MEN;

/**
 *
 */
static void    	display_menu();

/**
 *
 */
static Uint8   	process_input(SDL_Scancode const *s, t_menuentries *item);

static void	display_menu()
{
  SDL_Rect	rect;
  Uint8		i;

  rect = rect_factory(187, 122, 420, 119);
  renderer_clear(NULL);
  draw_sprite(get_sprite(get_spacesprites(), TITLE_SPR), &rect);
  for (i = 0; i < NB_MEN; ++i)
    draw_text(entries[i].text, &entries[i].orig, get_common_font(ATARI24_FNT),
	      item == i ? &entries[i].sel_color : &entries[i].uns_color);
  draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
}

static Uint8	process_input(SDL_Scancode const *s, t_menuentries *item)
{
  t_menuentries	old_item;

  old_item = *item;
  *item += (*s == get_input(UP_INP)->code && *item != START_MEN) ? -1 : 0;
  *item += (*s == get_input(DOWN_INP)->code && *item != SCORE_MEN) ? 1 : 0;
  if (*s == get_input(RETURN_INP)->code)
  {
    play_sfx(get_common_sfx(BLIPCANCEL_SFX));
    set_launcher(&space_destroy);
  }
  else if (*s == get_input(START_INP)->code)
  {
    if (entries[*item].enabled)
    {
      play_sfx(get_common_sfx(BLIPOK_SFX));
      set_launcher(entries[*item].callback);
    }
  }
  if (*item != old_item)
  {
    display_menu();
    play_sfx(get_common_sfx(BLIPSEL_SFX));
    return (1);
  }
  return (0);
}

void   		space_menu()
{
  SDL_Event    	e;

  display_menu();
  SDL_RenderPresent(get_renderer());
  while (get_launcher() == &space_menu)
  {
    if (SDL_WaitEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
	space_destroy();
	set_launcher(NULL);
	break;
      }
      if (e.type == SDL_KEYDOWN)
	if (!process_input(&e.key.keysym.scancode, &item))
	  continue;
      display_menu();
      SDL_RenderPresent(get_renderer());
    }
  }
}
