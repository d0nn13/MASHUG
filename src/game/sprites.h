/*
** sprites.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 00:59:08 2014 AHAMADA Samir
** Last update Sun Apr 27 23:33:15 2014 AHAMADA Samir
*/

/**
 *	Game Sprites
 */

#ifndef GAME_SPRITES_H
#define GAME_SPRITES_H

#include <SDL2/SDL_surface.h>

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
