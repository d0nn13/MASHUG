/*
** graphic_handler.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu May  1 18:21:08 2014 AHAMADA Samir
** Last update Thu Jun 19 22:22:55 2014 AHAMADA Samir
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

t_texture	*make_texture(SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h);

t_texture	*make_texture_from_surface(SDL_Renderer *r, SDL_Surface *s);

void		free_texture(t_texture *t);

#endif /* !GRAPHIC_HANDLER_H */
