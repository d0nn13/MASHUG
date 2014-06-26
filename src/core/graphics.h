/*
** graphics.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu May  1 18:21:08 2014 AHAMADA Samir
** Last update Thu Jun 26 17:12:42 2014 AHAMADA Samir
*/

/**
 *	@file	graphics.h
 *	@brief	Graphics and texture definitions
 */

#ifndef CORE_GRAPHICS_H
# define CORE_GRAPHICS_H

# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL_render.h>

/**
 *	@cond
 */
# if SDL_BYTEORDER == SDL_BIG_ENDIAN
#  define RMASK	0xff000000
#  define GMASK	0x00ff0000
#  define BMASK	0x0000ff00
#  define AMASK	0x000000ff
# else
#  define RMASK	0x000000ff
#  define GMASK	0x0000ff00
#  define BMASK	0x00ff0000
#  define AMASK	0xff000000
# endif

# define	PIX_FMT	SDL_PIXELFORMAT_RGBA8888
/**
 *	@endcond
 */

/**
 *	Texture wrapper structure
 */
typedef	struct	s_texture
{
  SDL_Texture	*tex;
  Uint16	w;
  Uint16	h;
}		t_texture;

/**
 *	@brief	Initializes graphics
 *
 *	@return 0 if the graphics initialization was succeeded
 *	@return -1 if the graphics initialization failed
 */
Sint32		graphics_init();

/**
 *	@brief	Background texture getter
 *
 *	@return a pointer to the background t_texture
 */
t_texture	*get_bg();

/**
 *	@brief Destroys graphics
 */
void		graphics_destroy();

#endif /* !CORE_GRAPHICS_H */
