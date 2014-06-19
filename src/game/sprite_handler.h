/*
** sprite_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 15:48:39 2014 AHAMADA Samir
** Last update Thu Jun 19 22:11:15 2014 AHAMADA Samir
*/

/**
 *	@file	sprite_handler.h
 *	@brief	Sprite handling interface
 */

#ifndef SPRITE_HANDLER_H
#define SPRITE_HANDLER_H

#include "graphics.h"
#include "sprites.h"

/**
 *	Allocates a new sprite from a sprites sheet,
 *	the function applies scaling
 *	'zone' : zone in the sprites sheet to take
 *	'size' : wanted sprite size
 */
t_texture	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size);

/**
 *	Draw a sprite 's' at a given rect in the texture,
 *	this function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit texture size
 */
void	draw_sprite(t_sprite s, SDL_Rect *zone);

/**
 *	Draw a sprite 's' at 'orig' point in the texture, without doing any scaling
 */	
void	draw_sprite_raw(t_sprite s, SDL_Point *orig);

#endif /* !SPRITE_HANDLER_H */
