/*
** display.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 22:08:12 2014 AHAMADA Samir
** Last update Tue Apr 22 17:40:10 2014 AHAMADA Samir
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "../../base/types.h"

#define WIN_WIDTH	800
#define WIN_HEIGHT	600

uInt32		Dspl_init();
void		Dspl_destroy();
SDL_Window	*Dspl_getWindow();
SDL_Renderer	*Dspl_getRender();

#endif /*! DISPLAY_H */
