/*
** graphics.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu May  1 18:22:44 2014 AHAMADA Samir
** Last update Sat May  3 17:06:01 2014 AHAMADA Samir
*/

#include "../core/log.h"
#include "../core/window.h"
#include "../core/renderer.h"
#include "graphic_handler.h"

static	t_texture	*bg;

Sint32	init_graphics()
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

void	destroy_graphics()
{
  free_texture(bg);
  SDL_LogInfo(GFX_LCAT, "Graphics destroyed");
}
