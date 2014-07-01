/*
** fonts.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 23:03:46 2014 AHAMADA Samir
** Last update Sat Jun 28 17:37:35 2014 AHAMADA Samir
*/

/**
 *	@file	fonts.h
 *	@brief	Common game fonts
 */

#ifndef GAME_COMMON_FONTS_H
# define GAME_COMMON_FONTS_H

# include <SDL2/SDL_ttf.h>

/**
 *	@brief	Common fonts enumeration
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
  } t_common_font;

/**
 *	@brief	Load game fonts in memory
 */
void		load_common_fonts();

/**
 *	@brief	Font getter
 *	@param	t The desired font in the t_font enumeration
 *	@return	A pointer to the desired font
 */
TTF_Font	*get_common_font(t_common_font t);

/**
 *	Frees allocated fonts
 */
void		free_common_fonts();

#endif /* !GAME_COMMON_FONTS_H */