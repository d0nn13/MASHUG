/*
** renderer.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:22:47 2014 AHAMADA Samir
** Last update Thu Jun 26 17:15:55 2014 AHAMADA Samir
*/

/**
 *	@file	renderer.h
 *	@brief	Rendering engine
 */

#ifndef CORE_RENDERER_H
# define CORE_RENDERER_H

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
 *	@brief	Destroys the Rendering engine
 */
void	renderer_destroy();

#endif /* !CORE_RENDERER_H */
