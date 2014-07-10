/*
** helpers.h for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core
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

SDL_Rect	rect_factory(const int x, const int y, const int w, const int h);
SDL_Point	point_factory(const int x, const int y);
SDL_Color	color_factory(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);

#endif /* CORE_HELPERS_H */
