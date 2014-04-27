/*
** sprite_handler.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Sun Apr 27 18:30:47 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "../core/renderer.h"
#include "sprite_handler.h"

void	draw_sprite(t_sprite s, SDL_Rect *zone)
{
  set_texture(SDL_CreateTextureFromSurface(get_renderer(), get_sprite(s)));
  SDL_SetTextureBlendMode(get_texture(), SDL_BLENDMODE_BLEND);
  SDL_RenderCopy(get_renderer(), get_texture(), NULL, zone);
  SDL_RenderPresent(get_renderer());
  SDL_LogInfo(RDR_LCAT, "Drawn sprite %d", s);
}

void		draw_sprite_raw(t_sprite s, SDL_Point *orig)
{
  SDL_Rect	zone;

  if (!orig)
    {
      SDL_LogError(SPR_LCAT, "Passed NULL origin point");
      return ;
    }
  zone = (SDL_Rect){orig->x, orig->y, get_sprite(s)->w, get_sprite(s)->h};
  draw_sprite(s, &zone);
}
