/*
** gameover.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Sun Sep  7 18:58:23 2014 ENNEBATI Yassine
** Last update Wed Sep 24 23:14:40 2014 ENNEBATI Yassine
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

#include "../../core/log.h"

#define	NB_LETTER 5

static void		display_header()
{
  SDL_Point		orig;
  SDL_Color const	white = {255, 255, 255, 255};
  SDL_Color const	red = {255, 0, 0, 0};

  orig = point_factory(265, 130);
  draw_text("GAME OVER", &orig, get_common_font(COSMIC48_FNT), &red);
  orig.x = 255;
  orig.y = 230;
  draw_text("UP and DOWN to change character",
	    &orig, get_common_font(ATARI12_FNT), &white);
  orig.x = 245;
  orig.y = 250;
  draw_text("LEFT and RIGHT to move the cursor",
	    &orig, get_common_font(ATARI12_FNT), &white);
  orig.x = 235;
  orig.y = 550;
  draw_text("Please ENTER to submit your hiscore",
	    &orig, get_common_font(ATARI12_FNT), &white);
}

static void		display_name(t_letter *name, Uint8 idx)
{
  SDL_Point		orig;
  char			buf[2];
  Uint8			i;

  renderer_clear(NULL);
  memset(buf, 0, 2);
  i = 0;
  display_header();
  orig = point_factory(345, 400);
  for (i = 0; i < NB_LETTER; ++i)
  {
    buf[0] = name[i].letter;
    draw_text(buf, &orig, get_common_font(COSMIC42_FNT),
	      idx == i ? &(name[i].sel_color) : &name[i].uns_color);
    orig.x += 29;
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
    if (gameover_process_events(name, &idx))
      break;
    display_name(name, idx);
    SDL_RenderPresent(get_renderer());
  }
}
