/*
** renderer.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:22:47 2014 AHAMADA Samir
** Last update Thu Jun 19 21:08:26 2014 AHAMADA Samir
*/

/**
 *	@file	renderer.h
 *	@brief	Rendering engine
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL_render.h>

/**
 * @fn Sint32 renderer_init()
 * @return 0 if the renderer initialization was succeeded
 * @brief Initializes Renderer SubSystem
 */
Sint32	renderer_init();

/**
 * @fn void renderer_destroy()
 * @return void
 * @brief Destroys Rendering SubSystem
 */
void	renderer_destroy();

/**
 * @fn SDL_Renderer *get_renderer()
 * @return a pointer on a SDL_Renderer struct
 * @brief Renderer getter
 */
SDL_Renderer	*get_renderer();

#endif /* !RENDERER_H */
