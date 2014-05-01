/*
** menu.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Apr 29 14:26:54 2014 AHAMADA Samir
** Last update Thu May  1 14:47:55 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include "font_handler.h"
#include "sound_handler.h"
#include "menu.h"

#define UP		SDL_SCANCODE_UP
#define DN		SDL_SCANCODE_DOWN
#define SEL		&(SDL_Color){255, 30, 30, 200}
#define UNS		&(SDL_Color){255, 255, 255, 200}
#define REDSEL(x)	((item == (x)) ? (SEL) : (UNS))

/**
 *	Menu item definition
 */
typedef enum
  {
    START_MEN,
    SCORE_MEN
  } t_menuitem;

/**
 *	Selected item
 */
static t_menuitem	item = START_MEN;

/**
 *	
 */
static void	process_input(const SDL_Scancode *s, t_menuitem *item);

/**
 *	
 */
static Sint32	key_filter(void *userdata, SDL_Event *event);

Sint32			menu_game()
{
  SDL_Event		e;
  SDL_Scancode		s;

  SDL_SetEventFilter(key_filter, NULL);
  while (1)
    {
      if (SDL_PollEvent(&e))
	{
	  if (e.type == SDL_QUIT)
	    return (-1);
	  if (e.type == SDL_KEYDOWN)
	    {
	      s = e.key.keysym.scancode;
	      process_input(&s, &item);
	      if (s == SDL_SCANCODE_RETURN || s == SDL_SCANCODE_KP_ENTER)
		break ;
	    }
	}
      display_menu();
      SDL_Delay(50);
    }
  return (item);
}

void	display_menu()
{
  draw_text("START", &(SDL_Point){312, 295}, ATARI24_FNT, REDSEL(START_MEN));
  draw_text("HISCORES", &(SDL_Point){280, 355}, ATARI24_FNT, REDSEL(SCORE_MEN));
}

static void	process_input(const SDL_Scancode *s, t_menuitem *item)
{
  t_menuitem	old_item;

  old_item = *item;
  *item += (*s == UP && *item != START_MEN) ? -1 : 0;
  *item += (*s == DN && *item != SCORE_MEN) ? 1 : 0;
  if (*item != old_item)
    play_sfx(BLIP_SFX);
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
