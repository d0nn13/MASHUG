/*
** mainmenu.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Tue Apr 29 14:26:54 2014 AHAMADA Samir
** Last update Fri Jun 27 17:46:38 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include "../core/handlers.h"
#include "common/sprites.h"
#include "common/fonts.h"
#include "common/sfx.h"
#include "gamecore.h"
#include "hiscores.h"

#include "mainmenu.h"

#define UP		SDL_SCANCODE_UP
#define DN		SDL_SCANCODE_DOWN
#define ISSEL(x, s, u)	((item == (x)) ? (s) : (u))

/**
 *	Menu item definition
 */
typedef enum
  {
    START_MEN,
    SCORE_MEN,
    NB_MEN
  }		t_menuitem;

/**
 *	Menu callback initialization
 */
static t_mode		select[NB_MEN] =
  {
    &game_loop,
    &hiscores
  };

static t_menuitem	item = START_MEN;

/**
 *
 */
static void		process_input(const SDL_Scancode *s, t_menuitem *item);

/**
 *
 */
static void		display_menu();

/**
 *
 */
static Sint32		key_filter(void *userdata, SDL_Event *event);

void			menu_game()
{
  SDL_Event		e;
  SDL_Scancode		s;

  SDL_SetEventFilter(key_filter, NULL);
  display_menu();
  while (g_launcher == &menu_game)
    {
      if (SDL_WaitEvent(&e))
	{
	  if (e.type == SDL_QUIT)
	    g_launcher = NULL;
	  if (e.type == SDL_KEYDOWN)
	    {
	      s = e.key.keysym.scancode;
	      process_input(&s, &item);
	    }
	}
    }
}

static void	process_input(const SDL_Scancode *s, t_menuitem *item)
{
  t_menuitem	old_item;

  old_item = *item;
  *item += (*s == UP && *item != START_MEN) ? -1 : 0;
  *item += (*s == DN && *item != SCORE_MEN) ? 1 : 0;
  if (*s == SDL_SCANCODE_ESCAPE)
    g_launcher = NULL;
  else if (*s == SDL_SCANCODE_RETURN || *s == SDL_SCANCODE_KP_ENTER)
    {
      g_launcher = select[*item];
      play_sfx(get_common_sfx(BLIPOK_SFX));
    }
  if (*item != old_item)
    {
      display_menu();
      play_sfx(get_common_sfx(BLIPSEL_SFX));
    }
}

static void		display_menu()
{
  const SDL_Color	sel = {152, 128, 208, 0};
  const SDL_Color	uns = {255, 255, 255, 0};
  SDL_Point	orig;

  orig.x = 187;
  orig.y = 122;
  draw_sprite_raw(get_common_sprite(TITLE_SPR), &orig);
  orig.x = 325;
  orig.y = 298;
  draw_text("START", &orig, get_common_font(ATARI24_FNT),
      ISSEL(START_MEN, &sel, &uns));
  orig.x = 289;
  orig.y = 369;
  draw_text("HISCORES", &orig, get_common_font(ATARI24_FNT),
      ISSEL(SCORE_MEN, &sel, &uns));
}

static Sint32	key_filter(void *userdata, SDL_Event *event)
{
  userdata = (void *)userdata;
  if (event->type != SDL_KEYDOWN && event->type != SDL_QUIT)
    return (0);
  if (event->type == SDL_KEYDOWN)
    if (event->key.keysym.scancode != UP && event->key.keysym.scancode != DN &&
  	event->key.keysym.scancode != SDL_SCANCODE_ESCAPE &&
  	event->key.keysym.scancode != SDL_SCANCODE_RETURN &&
  	event->key.keysym.scancode != SDL_SCANCODE_KP_ENTER)
      return (0);
  return (1);
}
