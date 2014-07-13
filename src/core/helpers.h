/*
** helpers.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Jul 09 21:56:05 2014 Samir Ahamada
** Last update Wed Jul 09 21:56:05 2014 Samir Ahamada
*/

/**
 *	@file	helpers.h
 *	@brief	Convinient helping functions
 */

#ifndef CORE_HELPERS_H
# define CORE_HELPERS_H

#include <SDL2/SDL.h>

#define UP		SDL_SCANCODE_UP
#define DN		SDL_SCANCODE_DOWN

SDL_Rect	rect_factory(const int x, const int y, const int w, const int h);
SDL_Point	point_factory(const int x, const int y);
SDL_Color	color_factory(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);

Sint32		key_filter(void *userdata, SDL_Event *event);

#endif /* CORE_HELPERS_H */
