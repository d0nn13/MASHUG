/*
** handlers.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Tue Jun 24 22:56:13 2014 AHAMADA Samir
** Last update Sat Jun 28 11:40:46 2014 AHAMADA Samir
*/

/**
 *	@file	handlers.h
 *	@brief	Handlers protoypes
 */

#ifndef CORE_HANLDERS_H
# define CORE_HANLDERS_H

# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL_render.h>
# include "graphics.h"
# include "audio.h"

/**
 * ==================== F O N T S ====================
 */
/**
 *	@brief	Allocates a new surface with 'text' printed with given
 *		font 'f' and color 'c'.
 *
 *	@param	text The string to be printed on the surface
 *	@param	f A pointer to the font to render the text with
 *	@param	c The color to render the text in
 *	@return	A pointer to the surface allocated with "text" printed
 *		with given font "f"and color "c"
 */
SDL_Surface	*get_text_surface(const char *text, const TTF_Font *f, const SDL_Color *c);

/**
 *	@brief	Draws some text at a given origin point, font and color.
 *
 *	@param	text The string to be drawn on the surface
 *	@param	orig A SDL_Point that defines the x and y coordinates of
 *		the text to be drawn
 *	@param	f A poiner to the font to render the text with
 *	@param	c The color to render the text in
 */
void		draw_text(const char *text, const SDL_Point *orig, const TTF_Font *f, const SDL_Color *c);


/**
 * ==================== G R A P H I C S ====================
 */
/**
 *	@brief	Create a texture for a rendering context.
 *
 *	@param	r The rendering context
 *	@param	a One of the enumerated values in SDL_TextureAccess
 *	@param	w The width of the texture in pixels
 *	@param	h The height of the texture in pixels
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_texture(const SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h);

/**
 *	@brief	Create a texture from an existing surface.
 *
 *	@param	r The rendering context
 *	@param	s The structure containing pixel data used to fill the texture
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_texture_from_surface(const SDL_Renderer *r, const SDL_Surface *s);

/**
 *	@brief	Deallocates a texture.
 *
 *	@param	t The texture to deallocate
 */
void		free_texture(t_texture *t);



/**
 * ==================== S O U N D  F X ====================
 */
/**
 *	@brief	Plays a sound effect.
 *
 *	@param	s The audio chunk to play
 */
void		play_sfx(t_chunk *s);


/**
 * ==================== S P R I T E S ====================
 */
/**
 *	@brief	Allocates a new scaled sprite from a sprites sheet file.
 *
 *	@param	file The file name of the sprites sheet containing the desired sprite
 *	@param	zone The zone in the sprites sheet to take
 *	@param	size The desired sprite size
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_sprite(const char *file, const SDL_Rect *zone, const SDL_Rect *size);

/**
 *	@brief	Draws a sprite at a given zone in the texture.
 *
 *	This function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit texture size
 *
 *	@param	s The desired sprite in t_sprite enumeration
 *	@param	zone The zone to fill with the desired sprite
 */
void		draw_sprite(const t_texture *s, const SDL_Rect *zone);

/**
 *	@brief	Draws a sprite at a given point in the texture without applying scaling.
 *
 *	@param	s The desired sprite in t_sprite enumeration
 *	@param	orig A SDL_Point that defines the x and y coordinates of the sprite to be drawn
 */
void		draw_sprite_raw(const t_texture *s, const SDL_Point *orig);


#endif /* !CORE_HANDLERS */
