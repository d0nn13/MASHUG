/*
** spacemenu.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:06:00 2014 ENNEBATI Yassine
** Last update Sun Jul 27 15:13:14 2014 ENNEBATI Yassine
*/

#include <SDL2/SDL.h>
#include "../../base/math.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "../mainmenu.h"
#include "spacespritesheet.h"
#include "spacehiscores.h"
#include "spacecore.h"

#include "spacemenu.h"

/**
 *	Menu item definition
 */
typedef enum
{
  START_MEN,
  SCORE_MEN,
  NB_MEN
}      	t_spaceitem;

/**
 *	Menu callback initialization
 */
static t_mode  	select[NB_MEN] =
{
  &space_loop,
  &hiscores
};

static t_spaceitem	item = START_MEN;

/**
 *
 */
static void    	process_input(SDL_Scancode const *s, t_spaceitem *item);

/**
 *
 */
static void    	display_menu();

void   		space_menu()
{
  SDL_Event    	e;
  SDL_Scancode 	s;

  SDL_SetEventFilter(key_filter, NULL);
  redraw_context(NULL);
  display_menu();
  while (g_launcher == &space_menu)
  {
    if (SDL_WaitEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
	space_destroy();
	g_launcher = NULL;
      }
      if (e.type == SDL_KEYDOWN)
      {
	s = e.key.keysym.scancode;
	process_input(&s, &item);
      }
    }
  }
}

static void	process_input(SDL_Scancode const *s, t_spaceitem *item)
{
  t_spaceitem	old_item;

  old_item = *item;
  *item += (*s == UP && *item != START_MEN) ? -1 : 0;
  *item += (*s == DN && *item != SCORE_MEN) ? 1 : 0;
  if (*s == SDL_SCANCODE_ESCAPE)
  {
    g_launcher = &main_menu;
    play_sfx(get_common_sfx(BLIPCANCEL_SFX));
    space_destroy();
  }
  else if (*s == SDL_SCANCODE_RETURN || *s == SDL_SCANCODE_KP_ENTER)
  {
    g_launcher = select[*item];
    play_sfx(get_common_sfx(BLIPOK_SFX));
    redraw_context(NULL);
  }
  if (*item != old_item)
  {
    display_menu();
    play_sfx(get_common_sfx(BLIPSEL_SFX));
  }
}

static void		display_menu()
{
  SDL_Color const	sel = {152, 128, 208, 0};
  SDL_Color const	uns = {255, 255, 255, 0};
  SDL_Point		orig;
  SDL_Rect		rect;
  TTF_Font const	*font;

  font = get_common_font(ATARI24_FNT);
  rect = rect_factory(187, 122, 420, 119);
  draw_sprite(get_sprite(get_space_spritesheet(), TITLE_SPR), &rect);
  orig = point_factory(325, 298);
  draw_text("START", &orig, font, T_EQ(item, START_MEN, &sel, &uns));
  orig = point_factory(289, 369);
  draw_text("HISCORES", &orig, font, T_EQ(item, SCORE_MEN, &sel, &uns));
}
