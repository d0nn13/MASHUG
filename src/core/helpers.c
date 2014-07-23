/*
** helpers.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Wed Jul 09 21:50:17 2014 Samir Ahamada
** Last update Wed Jul 23 13:27:26 2014 ENNEBATI Yassine
*/

/**
 *	@file	helpers.h
 *	@brief	Convinient helping functions
 */

#include "helpers.h"

SDL_Rect	rect_factory(const int x, const int y, const int w, const int h)
{
  SDL_Rect	newrect;

  newrect.x = x;
  newrect.y = y;
  newrect.w = w;
  newrect.h = h;
  return (newrect);
}

SDL_Point	point_factory(const int x, const int y)
{
  SDL_Point	newpoint;

  newpoint.x = x;
  newpoint.y = y;
  return (newpoint);
}

SDL_Color	color_factory(const Uint8 r,
			      const Uint8 g,
			      const Uint8 b,
			      const Uint8 a)
{
  SDL_Color	newcolor;

  newcolor.r = r;
  newcolor.g = g;
  newcolor.b = b;
  newcolor.a = a;
  return (newcolor);
}

Sint32	key_filter(void *userdata, SDL_Event *event)
{
  userdata = (void *)userdata;
  if (event->type != SDL_KEYDOWN && event->type != SDL_QUIT)
    return (0);
  if (event->type == SDL_KEYDOWN)
    if (event->key.keysym.scancode != UP && event->key.keysym.scancode != DN &&
  	event->key.keysym.scancode != SDL_SCANCODE_ESCAPE &&
  	event->key.keysym.scancode != SDL_SCANCODE_RETURN &&
  	event->key.keysym.scancode != SDL_SCANCODE_KP_ENTER)
      return (0);
  return (1);
}
