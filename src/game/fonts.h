/*
** fonts.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 23:03:46 2014 AHAMADA Samir
** Last update Sun Apr 27 23:21:46 2014 AHAMADA Samir
*/

/**
 *	Game Fonts
 */

#ifndef FONTS_H
#define FONTS_H

#include <SDL2/SDL_surface.h>

SDL_Surface	*make_font(const char* file);

void		load_fonts();

SDL_Surface	*get_font();

void		free_fonts();

#endif /* !FONTS_H */
