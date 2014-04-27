/*
** sprite_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 15:48:39 2014 AHAMADA Samir
** Last update Sun Apr 27 18:31:54 2014 AHAMADA Samir
*/

/**
 *	Sprite handling interface
 */

#ifndef SPRITE_HANLDER_H
#define SPRITE_HANLDER_H

#include "sprites.h"

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

#endif /* !SPRITE_HANLDER_H */
