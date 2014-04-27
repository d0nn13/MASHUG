/*
** math.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat Apr 26 11:25:42 2014 AHAMADA Samir
** Last update Sat Apr 26 12:06:05 2014 AHAMADA Samir
*/

#include "math.h"

Uint32	ctr(Uint32 d, Uint32 ref)
{
  int	off;

  off = 0;
  if (d >= ref)
    return (0);
  while (off + d/2 < ref/2)
    ++off;
  return (off);
}
