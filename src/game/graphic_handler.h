/*
** graphic_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu May  1 18:21:08 2014 AHAMADA Samir
** Last update Mon Jun 23 15:15:21 2014 AHAMADA Samir
*/

/**
 *	@file	graphic_handler.h
 *	@brief	Graphic handling interface
 */

#ifndef GRAPHIC_HANDLER_H
#define GRAPHIC_HANDLER_H

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_render.h>
#include "graphics.h"

/**
 *	@param r The rendering context
 *	@param a One of the enumerated values in SDL_TextureAccess
 *	@param w The width of the texture in pixels
 *	@param h The height of the texture in pixels
 *	@return A pointer to a newly heap allocated texture
 *	@brief Create a texture for a rendering context
 */
t_texture	*make_texture(SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h);

/**
 *	@param	r The rendering context
 *	@param	s The structure containing pixel data used to fill the texture
 *	@return	A pointer to a newly heap allocated texture
 *	@brief	Create a texture from an existing surface
 */
t_texture	*make_texture_from_surface(SDL_Renderer *r, SDL_Surface *s);

/**
 *	@param	t The texture to free
 *	@brief	Free one allocated texture
 */
void		free_texture(t_texture *t);

#endif /* !GRAPHIC_HANDLER_H */
