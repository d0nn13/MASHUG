/*
** renderer.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:22:47 2014 AHAMADA Samir
** Last update Tue Aug 12 22:06:06 2014 ENNEBATI Yassine
*/

/**
 *	@file	renderer.h
 *	@brief	Rendering engine
 */

#ifndef CORE_RENDERER_H_
# define CORE_RENDERER_H_

# include <SDL2/SDL_render.h>

/**
 *	@brief	Initializes Rendering engine
 *
 *	@return	0 if the renderer initialization was succeeded
 *	@return -1 if the renderer initialization failed
 */
Sint32	renderer_init();

/**
 *	@brief	Renderer getter
 *
 *	@return	a pointer to the engine's SDL_Renderer struct
 */
SDL_Renderer	*get_renderer();

/**
 *	@brief	Clears screen with color 'c'
 *	@param	c The color to clear the screen with
 */
void	renderer_clear(SDL_Color const *c);

/**
 *	@brief	Destroys the Rendering engine
 */
void	renderer_destroy();

#endif /* !CORE_RENDERER_H_ */
