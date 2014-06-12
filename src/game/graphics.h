/*
** graphics.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu May  1 18:21:08 2014 AHAMADA Samir
** Last update Sat May  3 16:06:47 2014 AHAMADA Samir
*/

/**
 *	Graphic definition and background texture management
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_render.h>

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  #define RMASK	0xff000000
  #define GMASK	0x00ff0000
  #define BMASK	0x0000ff00
  #define AMASK	0x000000ff
#else
  #define RMASK	0x000000ff
  #define GMASK	0x0000ff00
  #define BMASK	0x00ff0000
  #define AMASK	0xff000000
#endif

#define	PIX_FMT	SDL_PIXELFORMAT_RGBA8888

typedef	struct	s_texture
{
  SDL_Texture	*tex;
  Uint16	w;
  Uint16	h;
}		t_texture;

Sint32		init_graphics();
t_texture	*get_bg();
void		destroy_graphics();

#endif /* !GRAPHICS_H */