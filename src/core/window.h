/*
** window.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 22:08:12 2014 AHAMADA Samir
** Last update Sat May  3 12:24:57 2014 AHAMADA Samir
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL_video.h>

/**
 *	Window size definition
 */
#define WIN_W	768
#define WIN_H	672

/**
 *	Initializes Window SubSystem
 */
Sint32		window_init();

/**
 *	Destroys Window SubSystem
 */
void		window_destroy();

/**
 *	Window getter
 */
SDL_Window	*get_window();

#endif /*! WINDOW_H */
