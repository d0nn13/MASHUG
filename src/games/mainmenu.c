/*
** mainmenu.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/MASHUG
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Wed Jul  9 12:30:53 2014 ENNEBATI Yassine
** Last update Sat Jul 26 19:32:50 2014 ENNEBATI Yassine
*/

#include		"../base/math.h"
#include		"../core/renderer.h"
#include		"../core/input.h"
#include		"../core/handlers.h"
#include		"../core/helpers.h"
#include		"../core/launcher.h"
#include		"common/fonts.h"
#include		"common/sfx.h"
#include		"input_test.h"
#include		"spaceinvaders/spaceinvaders.h"

#include		"mainmenu.h"

/**
 *	Main menu entries enumeration
 */
typedef enum
{
  SPACE_GAME,
  GALAGA_GAME,
  NB_GAME
}	t_menuentries;

/**
 *	Space menu entries initialization
 */
static t_menuentry	entries[NB_GAME] =
{
  {
    "Space Invaders",
    {200, 300},
    {152, 128, 208, 0},
    {255, 255, 255, 0},
    &space_init,
    1
  },
  {
    "Galaga",
    {200, 400},
    {152, 128, 208, 0},
    {255, 255, 255, 0},
    NULL,
    0
  } 
};

static t_menuentries	item = SPACE_GAME;

/**
 *
 */
static void	display_menu();

/**
 *
 */
static void	process_input(SDL_Scancode const *s, t_menuentries *item);

static void	display_menu()
{
  Uint8		i;

  renderer_clear(NULL);
  for (i = 0; i < NB_GAME; ++i)
  {
    draw_text(entries[i].text, &entries[i].orig,
	      get_common_font(PRSTARTK24_FNT),
	      item == i ? &entries[i].sel_color : &entries[i].uns_color);
  }
}

static void	process_input(SDL_Scancode const *s, t_menuentries *item)
{
  t_menuentries	old_item;

  old_item = *item;
  *item += (*s == get_input(UP_INP)->code && *item != SPACE_GAME) ? -1 : 0;
  *item += (*s == get_input(DOWN_INP)->code && *item != GALAGA_GAME) ? 1 : 0;
  if (*s == get_input(RETURN_INP)->code)
    set_launcher(NULL);
  else if (*s == get_input(TEST_INP)->code)
    set_launcher(&input_test);
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
  }
}

void			main_menu()
{
  SDL_Event		e;

  while (get_launcher() == &main_menu)
  {
    display_menu();
    SDL_RenderPresent(get_renderer());
    if (SDL_WaitEvent(&e))
    {
      if (e.type == SDL_QUIT)
	set_launcher(NULL);
      if (e.type == SDL_KEYDOWN)
	process_input(&e.key.keysym.scancode, &item);
    }
  }
}
