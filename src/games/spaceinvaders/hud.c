/*
** hud.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sat Sep 20 20:17:32 2014 FOFANA Ibrahim
** Last update Sat Sep 20 21:06:10 2014 FOFANA Ibrahim
*/

#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../common/fonts.h"
#include "core.h"
#include "context.h"

#include "hud.h"

static void	display_score();
static void	display_lives();

void	display_hud()
{
  display_score();
  display_lives();
}

static void	display_score()
{
  SDL_Color const	green = {0, 255, 0, 0};
  SDL_Point		orig;
  char			str[20];

  orig = point_factory(get_spacebounds()->x + 10, get_spacebounds()->y - 8);
  draw_text("Score", &orig, get_common_font(PRSTARTK18_FNT), NULL);
  orig.x += 100;
  sprintf(str, "%d", get_spacecontext()->score);
  draw_text(str, &orig, get_common_font(PRSTARTK18_FNT), &green);
}

static void	display_lives()
{
  SDL_Point	orig;
  SDL_Rect	ship_lives;
  int		nb_lives;

  orig = point_factory(get_spacebounds()->x + 320, get_spacebounds()->y - 8);
  draw_text("Lives", &orig, get_common_font(PRSTARTK18_FNT), NULL);
  ship_lives = rect_factory(orig.x + 100, orig.y,
                            get_spaceobjects()->ship->rect.w, get_spaceobjects()->ship->rect.h);
  for (nb_lives = 1; nb_lives <= get_spacecontext()->lives; ++nb_lives)
  {
    draw_sprite(get_spaceobjects()->ship->sprite, &ship_lives);
    if (!(nb_lives % 4))
    {
      ship_lives.y = orig.y + get_spaceobjects()->ship->rect.h + 2;
      ship_lives.x = orig.x + 100;
    }
    else
      ship_lives.x += get_spaceobjects()->ship->rect.w + 10;
  }
}
