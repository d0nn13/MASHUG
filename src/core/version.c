/*
** version.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 21:10:45 2014 AHAMADA Samir
** Last update Mon Apr 21 21:20:09 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <SDL2/SDL_version.h>
#include "version.h"

static SDL_version v;

void       print_versions()
{
  SDL_GetVersion(&v);
  printf("v%d.%d.%d  [Using SDL v%d.%d.%d]\n\n",
	 SI_MAJOR, SI_MINOR, SI_PATCH,
	 v.major, v.minor, v.patch);
}
