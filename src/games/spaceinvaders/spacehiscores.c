/*
** spacehiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Sat Aug 23 12:33:13 2014 ENNEBATI Yassine
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

static t_hiscores	hiscores;

static Uint8	process_events()
{
  SDL_Event	e;

  if (!SDL_PollEvent(&e))
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

static Uint8   	load_hiscores()
{
  xml_hiscore_set_game_filter("spaceinvaders");
  hiscores.count = xml_parse("media/hiscores.xml", HISCORES_XML, NULL);
  if (!hiscores.count)
    return (0);
  hiscores.entries = mem_alloc(hiscores.count, sizeof(t_hiscoreholder)); 
  xml_parse("media/hiscores.xml", HISCORES_XML, hiscores.entries);
  return (1);
}

static void    		display_hiscores()
{
  SDL_Color const	green = {0, 255, 0, 255};
  SDL_Point		orig;
  char			*score;
  int			i;

  score = NULL;
  orig = point_factory(200, 130);
  draw_text("NAME", &orig, get_common_font(COSMIC24_FNT), &green);
  orig = point_factory(400, 130);
  draw_text("SCORE", &orig, get_common_font(COSMIC24_FNT), &green);
  orig = point_factory(200, 170);
  for (i = 0; i < hiscores.count; ++i)
  {
    draw_text(hiscores.entries[i].nickname, &orig,
	      get_common_font(COSMIC24_FNT), &green);
    orig.x += 200;
    score = mem_alloc(1, 32);
    sprintf(score, "%u", hiscores.entries[i].score);
    draw_text(score, &orig, get_common_font(COSMIC24_FNT), &green);
    mem_free(score);
    orig.x -= 200;
    orig.y += 50;
  }
}

void			spacehiscores()
{
  renderer_clear(NULL);
  draw_sprite(get_sprite(get_spacesprites(), CABINET_SPR), NULL);
  if (!load_hiscores())
  {
    SDL_LogDebug(APP_LCAT, "Couldn't load Space Invaders hiscores");
    return ;
  }
  while (get_launcher() == &spacehiscores)
  {
    SDL_RenderPresent(get_renderer());
    if (process_events())
      break;
    display_hiscores();
  }
}

Uint8	save_spacehiscores();
