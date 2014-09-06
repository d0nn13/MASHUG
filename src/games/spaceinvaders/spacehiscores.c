/*
** spacehiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Thu Sep  4 22:05:45 2014 ENNEBATI Yassine
*/

#include <stdio.h>
#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "spacesprites.h"
#include "spacecore.h"
#include "spacemenu.h"

#include "spacehiscores.h"


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

static Uint8   	load_hiscores(t_hiscores *hiscores)
{
  xml_hiscore_set_game_filter("spaceinvaders");
  hiscores->count = xml_parse("media/hiscores.xml", HISCORES_XML, NULL);
  if (!hiscores->count)
    return (0);
  hiscores->entries = mem_alloc(hiscores->count, sizeof(t_hiscoreholder)); 
  xml_parse("media/hiscores.xml", HISCORES_XML, hiscores->entries);
  return (1);
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

static void    		display_hiscores(t_hiscores hiscores)
{
  SDL_Color const	yellow = {0, 255, 0, 0};
  SDL_Color const	green = {255, 0, 0, 0};
  SDL_Point		orig;
  char			position[3];
  Uint8			i;

  memset(position, 0, sizeof(position));
  renderer_clear(NULL);
  orig = point_factory(330, 130);
  draw_text("TOP 10", &orig, get_common_font(COSMIC24_FNT), &green);
  orig = point_factory(220, 170);
  for (i = 1; i < hiscores.count; ++i)
  {
    sprintf(position, "%d", i);
    draw_text(position, &orig, get_common_font(COSMIC18_FNT), &yellow);
    draw_hiscores_entries(orig, hiscores.entries[i - 1]);
    orig.y += 40;
  }
  draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
}

void		spacehiscores()
{
  t_hiscores	hiscores;
  Uint8		i;

  if (!load_hiscores(&hiscores))
  {
    SDL_LogDebug(APP_LCAT, "Couldn't load Space Invaders hiscores");
    return ;
  }
  display_hiscores(hiscores);
  SDL_RenderPresent(get_renderer());
  while (get_launcher() == &spacehiscores)
    if (process_events())
    {
      for (i = 0; i < hiscores.count; ++i)
	mem_free(hiscores.entries[i].nickname);
      mem_free(hiscores.entries);
      break;
    }
}

Uint8	save_spacehiscores();
