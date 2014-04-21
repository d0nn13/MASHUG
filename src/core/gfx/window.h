/*
** window.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 22:08:12 2014 AHAMADA Samir
** Last update Mon Apr 21 12:25:20 2014 AHAMADA Samir
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

#define WIN_WIDTH	800
#define WIN_HEIGHT	600

int		Win_init();
int		Win_destroy();
SDL_Window	*Win_getWindow();
SDL_Renderer	*Win_getRenderer();

#endif /*! WINDOW_H */
