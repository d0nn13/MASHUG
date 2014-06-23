/*
** font_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 28 15:34:14 2014 AHAMADA Samir
** Last update Sat Jun 21 15:25:23 2014 ENNEBATI Yassine
*/

/**
 *	@file	font_handler.c
 *	@brief	Font handling interface
 */

#ifndef FONT_HANLDER_H
#define FONT_HANLDER_H

#include "fonts.h"

/**
 *	@brief	Allocates a new surface with 'text' printed with given
 *		font 'f' and color 'c'.
 *	@param	text The string to be printed on the surface.
 *	@param	f Font to render the text with.
 *	@param	c The color to render the text in.
 *	@return	A pointer to the surface allocated with "text" printed with given font "f"and color "c".
 */
SDL_Surface	*get_text_surface(const char *text, t_font f, SDL_Color *c);

/**
 *	@brief	Draws 'text' at a given 'orig' with font 'f' and color 'c'.
 *	@param	text The string to be drawn on the surface.
 *	@param	orig A SDL_Point that defines the x and y coordinates of the origin of the text to be drawn.
 *	@param	f Font to render the text with.
 *	@param	c The color to render the text in.
 */
void		draw_text(const char *text, SDL_Point *orig, t_font f, SDL_Color *c);

#endif /* !FONT_HANDLER */
