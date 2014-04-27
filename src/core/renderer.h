/*
** renderer.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 11:22:47 2014 AHAMADA Samir
** Last update Sun Apr 27 18:40:01 2014 AHAMADA Samir
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL_render.h>

/**
 *	Initializes Rendering SubSystem
 */
Sint32	renderer_init();

/**
 *	Destroys Rendering SubSystem
 */
void	renderer_destroy();

/**
 *	Renderer getter
 */
SDL_Renderer	*get_renderer();

/**
 *	Texture getter
 */
SDL_Texture	*get_texture();

/**
 *	Texture setter
 */
void		set_texture(SDL_Texture *t);

#endif /* !RENDERER_H */
