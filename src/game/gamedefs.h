/*
** gamedefs.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 23:09:59 2014 AHAMADA Samir
** Last update Sun Apr 27 23:11:16 2014 AHAMADA Samir
*/

/**
 *	Game shared defs
 */

#ifndef GAMEDEFS_H
#define GAMEDEFS_H

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  #define RMASK	0xff000000
  #define GMASK	0x00ff0000
  #define BMASK	0x0000ff00
  #define AMASK	0x000000ff
#else
  #define RMASK	0x000000ff
  #define GMASK	0x0000ff00
  #define BMASK	0x00ff0000
  #define AMASK	0xff000000
#endif

#endif /* !GAMEDEFS_H */
