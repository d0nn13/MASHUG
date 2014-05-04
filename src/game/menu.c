/*
** menu.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Apr 29 14:26:54 2014 AHAMADA Samir
** Last update Sun May  4 13:51:00 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include "gamecore.h"
#include "hiscores.h"
#include "sprite_handler.h"
#include "font_handler.h"
#include "sound_handler.h"
#include "menu.h"

#define UP		SDL_SCANCODE_UP
#define DN		SDL_SCANCODE_DOWN
#define SEL		&(SDL_Color){152, 128, 208, 0}
#define UNS		&(SDL_Color){255, 255, 255, 0}
#define ISSEL(x)	((item == (x)) ? (SEL) : (UNS))

/**
 *	Menu item definition
 */
typedef enum
  {
    START_MEN,
    SCORE_MEN
  }		t_menuitem;

/**
 *	Menu callback initialization
 */
static t_mode		select[2] =
  {
    game_loop,
    hiscores
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

void	menu_game()
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
	      if (s == SDL_SCANCODE_RETURN || s == SDL_SCANCODE_KP_ENTER)
		g_launcher = select[item];
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
  if (*item != old_item)
    {
      display_menu();
      play_sfx(BLIP_SFX);
    }
}

static void	display_menu()
{
  t_texture	*tex;

  tex = get_sprite(TITLE_SPR);
  draw_sprite_raw(TITLE_SPR, &(SDL_Point){187, 122});
  draw_text("START", &(SDL_Point){325, 298}, ATARI24_FNT, ISSEL(START_MEN));
  draw_text("HISCORES", &(SDL_Point){289, 369}, ATARI24_FNT, ISSEL(SCORE_MEN));
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

