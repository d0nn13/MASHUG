/*
** input_test.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Aug 06 16:10:21 2014 Samir Ahamada
** Last update Wed Aug 06 16:10:21 2014 Samir Ahamada
*/

#include <SDL2/SDL.h>
#include "../core/log.h"
#include "../core/renderer.h"
#include "../core/input.h"
#include "../core/launcher.h"
#include "../core/handlers.h"
#include "../core/helpers.h"
#include "common/fonts.h"
#include "mainmenu.h"

#include "input_test.h"

static void	input_test_display()
{
  SDL_Point	o;
  Uint8		i;
  char		statestr[] = "  ";

  SDL_RenderClear(get_renderer());
  o = point_factory(192, 10);
  draw_text("INPUT TEST MODE", &o, get_common_font(5), NULL);
  o = point_factory(138, 640);
  draw_text("PRESS UP+FIRE TO QUIT", &o, get_common_font(5), NULL);
  o = point_factory(260, 200);
  input_update();
  for (i = 0; i < NB_INP; ++i)
  {
    sprintf(statestr, "%d", get_input(i)->state);
    draw_text(get_input(i)->key, &o, get_common_font(1), NULL);
    o.x += 200;
    draw_text(statestr, &o, get_common_font(1), NULL);
    o.y += 32;
    o.x -= 200;
  }
}

void		input_test()
{
  SDL_Event	e;
  Uint32	ti;
  Uint32	to;

  input_flush();
  while (get_launcher() == &input_test)
  {
    ti = SDL_GetTicks();
    if (SDL_PollEvent(&e))
      if (e.type == SDL_QUIT)
	set_launcher(NULL);
    if (get_input(UP_INP)->state && get_input(FIRE_INP)->state)
      set_launcher(&main_menu);
    input_test_display();
    SDL_RenderPresent(get_renderer());
    to = SDL_GetTicks() - ti;
    if (to < 50)
      SDL_Delay(50 - to);
  }
}

