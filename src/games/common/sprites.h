/*
** sprites.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 00:59:08 2014 AHAMADA Samir
** Last update Mon Jul 14 13:26:52 2014 ENNEBATI Yassine
*/

/**
 *	@file	sprites.h
 *	@brief	Common game sprites
 */

#ifndef GAMES_COMMON_SPRITES_H
# define GAMES_COMMON_SPRITES_H

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

#endif /* !GAMES_COMMON_SPRITES_H */
