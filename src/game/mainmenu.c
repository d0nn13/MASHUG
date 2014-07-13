/*
** mainmenu.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/MASHUG
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Wed Jul  9 12:30:53 2014 ENNEBATI Yassine
** Last update Wed Jul  9 23:57:51 2014 ENNEBATI Yassine
*/

#include		"../base/math.h"
#include		"../core/renderer.h"
#include		"../core/handlers.h"
#include		"../core/helpers.h"
#include		"common/fonts.h"
#include		"common/sfx.h"
#include		"spaceinvaders/menu.h"
#include		"spaceinvaders/gamecore.h"

#include		"mainmenu.h"

typedef enum
{
  SPACE_GAME,
  GALAGA_GAME,
  NB_GAME
}	t_gameitem;

static t_gameitem	item = SPACE_GAME;

static t_mode		select[NB_GAME] =
  {
    &menu_game,
    &main_menu
  };

static void		display_main_menu();

static void		process_input(const SDL_Scancode *s, t_gameitem *item);

static void		draw_background_menu();


static void		display_main_menu()
{
  const SDL_Color	sel = {152, 128, 208, 0};
  const SDL_Color	uns = {255, 255, 255, 0};
  SDL_Point		orig;
  
  orig = point_factory(200, 300);
  draw_text("Space Invaders", &orig, get_common_font(PRSTARTK24_FNT),
            T_EQ(item, SPACE_GAME, &sel, &uns));
  orig = point_factory(200, 400);
  draw_text("Galaga", &orig, get_common_font(PRSTARTK24_FNT),
	    T_EQ(item, GALAGA_GAME, &sel, &uns));
}

static void	process_input(const SDL_Scancode *s, t_gameitem *item)
{
  t_gameitem	old_item;

  old_item = *item;
  *item += (*s == UP && *item != SPACE_GAME) ? -1 : 0;
  *item += (*s == DN && *item != GALAGA_GAME) ? 1 : 0;
  if (*s == SDL_SCANCODE_ESCAPE)
    g_launcher = NULL;
  else if (*s == SDL_SCANCODE_RETURN || *s == SDL_SCANCODE_KP_ENTER)
    {
      g_launcher = select[*item];
      if (*item != GALAGA_GAME)
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
  const SDL_Color	col = {0, 0, 0, 255};
  
  SDL_SetRenderDrawColor(get_renderer(), col.r, col.g, col.b, col.a);
  SDL_RenderClear(get_renderer());
}

void			main_menu()
{
  SDL_Event		e;
  SDL_Scancode		s;

  draw_background_menu();
  SDL_SetEventFilter(key_filter, NULL);
  display_main_menu();
  while (g_launcher == &main_menu)
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
