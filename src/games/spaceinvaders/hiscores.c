/*
** hiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Fri Sep 26 03:33:48 2014 ENNEBATI Yassine
*/

#include <stdio.h>
#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../../core/launcher.h"
#include "../../core/helpers/hiscores_io.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "sprites.h"
#include "core.h"
#include "menu.h"

#include "hiscores.h"

static Uint8	process_events()
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
  }
  return (0);
}

static void		draw_hiscores_entries(SDL_Point orig, t_hiscoreholder entry)
{
  SDL_Color const	white = {255, 255, 255, 0};
  char			score[6];

  memset(score, 0, sizeof(score));
  orig.x += 80;
  draw_text(entry.nickname, &orig,
	    get_common_font(COSMIC18_FNT), &white);
  orig.x += 200;
  sprintf(score, "%u", entry.score);
  draw_text(score, &orig, get_common_font(COSMIC18_FNT), &white);
}

static void		display_hiscores(t_hiscores hiscores)
{
  SDL_Color const	yellow = {0, 255, 0, 0};
  SDL_Color const	green = {255, 0, 0, 0};
  SDL_Point		orig;
  char			position[3];
  Uint8			i;

  memset(position, 0, sizeof(position));
  renderer_clear(NULL);
  orig = point_factory(365, 140);
  draw_text("TOP 10", &orig, get_common_font(COSMIC24_FNT), &green);
  orig = point_factory(255, 200);
  for (i = 1; i <= hiscores.count; ++i)
  {
    if (i == hiscores.count)
      orig.x = 245;
    sprintf(position, "%d", i);
    draw_text(position, &orig, get_common_font(COSMIC18_FNT), &yellow);
    orig.x = 255;
    draw_hiscores_entries(orig, hiscores.entries[i - 1]);
    orig.y += 40;
  }
  draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
}

void		spacehiscores()
{
  t_hiscores	hiscores;

  if (!load_hiscores(&hiscores, "spaceinvaders"))
  {
    SDL_LogDebug(APP_LCAT, "Couldn't load Space Invaders hiscores");
    return ;
  }
  display_hiscores(hiscores);
  SDL_RenderPresent(get_renderer());
  while (get_launcher() == &spacehiscores)
    if (process_events())
    {
      free_hiscores(&hiscores);
      break;
    }
}
