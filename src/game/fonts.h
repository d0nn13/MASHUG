/*
** fonts.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 23:03:46 2014 AHAMADA Samir
** Last update Thu May  1 14:16:10 2014 AHAMADA Samir
*/

/**
 *	Game Fonts
 */

#ifndef FONTS_H
#define FONTS_H

#include <SDL2/SDL_ttf.h>

/**
 *	Sprite names enumeration
 */
typedef enum
  {
    ATARI24_FNT = 0,
    ATARI18_FNT,
    COSMIC18_FNT,
    COSMIC12_FNT,
    NB_FNT
  } t_font;

/**
 *	Load game fonts in memory
 */
void		load_fonts();

/**
 *	Font getter
 */
TTF_Font	*get_font(t_font t);

/**
 *	Frees allocated fonts
 */
void		free_fonts();

#endif /* !FONTS_H */
