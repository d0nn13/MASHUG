/*
** sprites.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 00:59:08 2014 AHAMADA Samir
** Last update Thu Jun 19 21:44:54 2014 AHAMADA Samir
*/

/**
 *	@file	sprites.h
 *	@brief	Game Sprites
 */

#ifndef GAME_COMMON_SPRITES_H
#define GAME_COMMON_SPRITES_H

#include <SDL2/SDL_render.h>

/**
 *	Sprite names enumeration
 */
typedef enum
  {
    CABINET_SPR = 0,
    TITLE_SPR,
    NB_SPR
  } t_sprite;

/**
 *	Load game sprites in memory
 */
void		load_sprites();

/**
 *	Sprite getter
 */
t_texture	*get_sprite(t_sprite s);

/**
 *	Frees allocated sprites
 */
void		free_sprites();

#endif /* !GAME_COMMON_SPRITES_H */
