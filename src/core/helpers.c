/*
** helpers.c for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Jul 09 21:50:17 2014 Samir Ahamada
** Last update Wed Jul 09 21:50:17 2014 Samir Ahamada
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