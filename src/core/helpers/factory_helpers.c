/*
** factory_helpers.c for helpers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Jul 29 12:32:48 2014 Samir Ahamada
** Last update Tue Jul 29 12:32:48 2014 Samir Ahamada
*/

/**
 *	@file	factory_helpers.h
 *	@brief	Convinient helping factory functions
 */

#include "../helpers.h"

SDL_Rect	rect_factory(int const x, int const y, int const w, int const h)
{
  SDL_Rect	newrect;

  newrect.x = x;
  newrect.y = y;
  newrect.w = w;
  newrect.h = h;
  return (newrect);
}

SDL_Point	point_factory(int const x, int const y)
{
  SDL_Point	newpoint;

  newpoint.x = x;
  newpoint.y = y;
  return (newpoint);
}

SDL_Color	color_factory(Uint8 const r,
			      Uint8 const g,
			      Uint8 const b,
			      Uint8 const a)
{
  SDL_Color	newcolor;

  newcolor.r = r;
  newcolor.g = g;
  newcolor.b = b;
  newcolor.a = a;
  return (newcolor);
}

