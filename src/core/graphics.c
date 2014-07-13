/*
** graphics.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu May  1 18:22:44 2014 AHAMADA Samir
** Last update Tue Jun 24 23:11:56 2014 AHAMADA Samir
*/

/**
 *	@file	graphics.c
 *	@brief	Graphics and texture definitions
 */

#include "../core/log.h"
#include "../core/window.h"
#include "../core/renderer.h"

#include "handlers.h"

static	t_texture	*bg;

Sint32	graphics_init()
{
  if (!(bg = make_texture(get_renderer(), SDL_TEXTUREACCESS_STATIC,
			  WIN_W, WIN_H)))
    {
      SDL_LogError(GFX_LCAT, "Couldn't initialize graphics : ", SDL_GetError());
      return (-1);
    }
  SDL_LogInfo(GFX_LCAT, "Graphics initialization done");
  return (0);
}

t_texture	*get_bg()
{
  return (bg);
}

void	graphics_destroy()
{
  free_texture(bg);
  SDL_LogInfo(GFX_LCAT, "Graphics destroyed");
}
