/*
** sprite_handler.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 15:29:34 2014 AHAMADA Samir
** Last update Thu Sep 25 23:06:08 2014 Emmanuel Atse
*/

/**
 *	@file	sprite_handler.c
 *	@brief	Sprite handling interface
 */

#include "../../base/memory.h"
#include "../log.h"
#include "../renderer.h"
#include "../helpers.h"

#include "../handlers.h"

void		draw_sprite(t_spriteholder const *s,
			    SDL_Rect const *zone)
{
  SDL_Renderer	*renderer;

  if (!ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite") ||
      !ptr_chk(s->sheet, "s->sheet", SPR_LCAT, "draw_sprite"))
    return ;
  renderer = get_renderer();
  SDL_RenderCopy(renderer, s->sheet->tex->tex, &s->rect, zone);
  SDL_LogVerbose(SPR_LCAT, "Drawn sprite '%s'", s->name);
}

void		draw_sprite_ex(t_spriteholder const *s,
			       SDL_Rect const *zone,
			       double angle,
			       SDL_RendererFlip flip)
{
  SDL_Renderer	*renderer;

  if (!ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite") ||
      !ptr_chk(s->sheet, "s->sheet", SPR_LCAT, "draw_sprite"))
    return ;
  renderer = get_renderer();
  SDL_RenderCopyEx(renderer, s->sheet->tex->tex, &s->rect, zone,
		   angle, NULL, flip);
  SDL_LogVerbose(SPR_LCAT, "Drawn sprite '%s'", s->name);
}

void		draw_sprite_raw(t_spriteholder const *s,
				SDL_Point const *orig)
{
  SDL_Rect	rect;

  if (!ptr_chk(s, "sprite", SPR_LCAT, "draw_sprite_raw") ||
      !ptr_chk(orig, "origin", SPR_LCAT, "draw_sprite_raw"))
    return ;
  rect = rect_factory(orig->x, orig->y, s->rect.w, s->rect.h);
  draw_sprite(s, &rect);
}

