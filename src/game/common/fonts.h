/*
** fonts.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 23:03:46 2014 AHAMADA Samir
** Last update Sat Jun 21 15:26:03 2014 ENNEBATI Yassine
*/

/**
 *	@file	fonts.h
 *	@brief	Game Fonts
 */

#ifndef GAME_COMMON_FONTS_H
#define GAME_COMMON_FONTS_H

#include <SDL2/SDL_ttf.h>

/**
 *	@brief	Sprite names enumeration
 */
typedef enum
  {
    ATARI24_FNT = 0,
    ATARI18_FNT,
    COSMIC48_FNT,
    COSMIC24_FNT,
    COSMIC18_FNT,
    COSMIC12_FNT,
    NB_FNT
  } t_font;

/**
 *	@brief	Load game fonts in memory
 */
void		load_fonts();

/**
 *	@brief	Font getter
 *	@param	t The desired font in the t_font enumeration
 *	@return	A pointer to the desired font
 */
TTF_Font	*get_font(t_font t);

/**
 *	Frees allocated fonts
 */
void		free_fonts();

#endif /* !GAME_COMMON_FONTS_H */
