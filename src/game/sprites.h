/*
** sprites.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 00:59:08 2014 AHAMADA Samir
** Last update Sun Apr 27 18:37:20 2014 AHAMADA Samir
*/

/**
 *	Game Sprites
 */

#ifndef GAME_SPRITES_H
#define GAME_SPRITES_H

#include <SDL2/SDL_surface.h>

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

/**
 *	Sprite names enumeration
 */
typedef enum
  {
    CABINET_SPR,
    TITLE_SPR,
    LAST_SPR
  } t_sprite;

/**
 *	Allocates a new sprite from a sprites sheet,
 *	the function applies scaling
 *	'zone' : zone in the sprites sheet to take
 *	'size' : wanted sprite size
 */
SDL_Surface	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size);

/**
 *	Load game sprites in memory
 */
void		load_sprites();

/**
 *	Sprite getter
 */
SDL_Surface	*get_sprite(t_sprite s);

/**
 *	Frees allocated sprites
 */
void		free_sprites();

#endif /* !GAME_SPRITES_H */
