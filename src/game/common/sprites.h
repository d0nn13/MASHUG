/*
** sprites.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 00:59:08 2014 AHAMADA Samir
** Last update Sat Jun 28 17:38:13 2014 AHAMADA Samir
*/

/**
 *	@file	sprites.h
 *	@brief	Common game sprites
 */

#ifndef GAME_COMMON_SPRITES_H
# define GAME_COMMON_SPRITES_H

# include <SDL2/SDL_render.h>

/**
 *	Common sprites enumeration
 */
typedef enum
  {
    CABINET_SPR = 0,
    TITLE_SPR,
    NB_SPR
  } t_common_sprite;

/**
 *	Load game sprites in memory
 */
void		load_common_sprites();

/**
 *	Sprite getter
 */
t_texture	*get_common_sprite(t_common_sprite s);

/**
 *	Frees allocated sprites
 */
void		free_common_sprites();

#endif /* !GAME_COMMON_SPRITES_H */
