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
#include		"spaceinvaders/spaceinvaders.h"

#include		"mainmenu.h"

typedef enum
{
  SPACE_GAME,
  GALAGA_GAME,
  NB_GAME
}	t_gameitem;

static t_gameitem	item = SPACE_GAME;

static t_exec		select[NB_GAME] =
{
  &space_init,
  &main_menu
};

static void		display_main_menu();

static void		process_input(SDL_Scancode const *s, t_gameitem *item);

static void		draw_background_menu();

static void		display_main_menu()
{
  SDL_Color const	sel = {152, 128, 208, 0};
  SDL_Color const	uns = {255, 255, 255, 0};
  SDL_Point		orig;

  orig = point_factory(200, 300);
  draw_text("Space Invaders", &orig, get_common_font(PRSTARTK24_FNT),
            T_EQ(item, SPACE_GAME, &sel, &uns));
  orig = point_factory(200, 400);
  draw_text("Galaga", &orig, get_common_font(PRSTARTK24_FNT),
	    T_EQ(item, GALAGA_GAME, &sel, &uns));
}

static void	process_input(SDL_Scancode const *s, t_gameitem *item)
{
  t_gameitem	old_item;

  old_item = *item;
  *item += (*s == UP && *item != SPACE_GAME) ? -1 : 0;
  *item += (*s == DN && *item != GALAGA_GAME) ? 1 : 0;
  if (*s == SDL_SCANCODE_ESCAPE)
    set_launcher(NULL);
  else if (*s == SDL_SCANCODE_RETURN || *s == SDL_SCANCODE_KP_ENTER)
  {
    set_launcher(select[*item]);
    if (*item == SPACE_GAME)
      play_sfx(get_common_sfx(BLIPOK_SFX));
  }
  if (*item != old_item)
  {
    display_main_menu();
    play_sfx(get_common_sfx(BLIPSEL_SFX));
  }
}

static void		draw_background_menu()
{
  SDL_Color const	col = {0, 0, 0, 255};

  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
}

void			main_menu()
{
  SDL_Event		e;
  SDL_Scancode		s;

  draw_background_menu();
  display_main_menu();
  while (get_launcher() == &main_menu)
  {
    SDL_RenderPresent(get_renderer());
    if (SDL_WaitEvent(&e))
    {
      if (e.type == SDL_QUIT)
	set_launcher(NULL);
      if (e.type == SDL_KEYDOWN)
      {
	s = e.key.keysym.scancode;
	process_input(&s, &item);
      }
    }
  }
}
