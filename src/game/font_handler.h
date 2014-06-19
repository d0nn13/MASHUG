/*
** font_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 28 15:34:14 2014 AHAMADA Samir
** Last update Thu Jun 19 22:10:54 2014 AHAMADA Samir
*/

/**
 *	@file	font_handler.c
 *	@brief	Font handling interface
 */

#ifndef FONT_HANLDER_H
#define FONT_HANLDER_H

#include "fonts.h"

/**
 *	Allocates a new surface with 'text' printed with given
 *	font 'f' and color 'c'
 */
SDL_Surface	*get_text_surface(const char *text, t_font f, SDL_Color *c);

/**
 *	Draws 'text' at a given 'orig' with font 'f' and color 'c'
 */
void		draw_text(const char *text, SDL_Point *orig, t_font f, SDL_Color *c);

#endif /* !FONT_HANDLER */
