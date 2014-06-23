/*
** sprite_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 15:48:39 2014 AHAMADA Samir
** Last update Mon Jun 23 19:31:16 2014 AHAMADA Samir
*/

/**
 *	@file	sprite_handler.h
 *	@brief	Sprite handling interface
 */

#ifndef SPRITE_HANDLER_H
#define SPRITE_HANDLER_H

#include "../../core/graphics.h"
#include "../common/sprites.h"

/**
 *	@brief	Allocates a new scaled sprite from a sprites sheet file.
 *
 *	@param	file The file name of the sprites sheet containing the desired sprite
 *	@param	zone The zone in the sprites sheet to take
 *	@param	size The desired sprite size
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_sprite(const char *file, SDL_Rect *zone, SDL_Rect *size);

/**
 *	@brief	Draws a sprite at a given zone in the texture.
 *
 *	This function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit texture size
 *
 *	@param	s The desired sprite in t_sprite enumeration
 *	@param	zone The zone to fill with the desired sprite 
 */
void	draw_sprite(t_sprite s, SDL_Rect *zone);

/**
 *	@brief	Draws a sprite at a given point in the texture without applying scaling.
 *
 *	@param	s The desired sprite in t_sprite enumeration
 *	@param	orig A SDL_Point that defines the x and y coordinates of the sprite to be drawn
 */	
void	draw_sprite_raw(t_sprite s, SDL_Point *orig);

#endif /* !SPRITE_HANDLER_H */
