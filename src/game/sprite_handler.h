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
 *	@param	file The file name of the sprites sheet containing the desired sprite
 *	@param	zone The zone in the sprites sheet to take
 *	@param	size The desired sprite size
 *	@return	A pointer to a newly heap allocated texture
 *	@brief	Allocates a new scaled sprite from a sprites sheet
 */
t_texture	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size);

/**
 *	Draws a sprite 's' at a given zone in the texture,
 *	this function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit texture size
 */
void	draw_sprite(t_sprite s, SDL_Rect *zone);

/**
 *	Draws a sprite 's' at 'orig' point in the texture, without doing any scaling
 */	
void	draw_sprite_raw(t_sprite s, SDL_Point *orig);

#endif /* !SPRITE_HANDLER_H */
