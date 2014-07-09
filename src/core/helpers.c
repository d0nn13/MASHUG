/*
** helpers.c for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/core
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Jul 09 21:50:17 2014 Samir Ahamada
** Last update Wed Jul 09 21:50:17 2014 Samir Ahamada
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
