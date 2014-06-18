/*
** window.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 22:08:12 2014 AHAMADA Samir
** Last update Thu Jun 19 21:12:15 2014 AHAMADA Samir
*/

/**
 *	@file	window.h
 *	@brief	Window handling engine
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL_video.h>

/**
 *	Window weight size
 */
#define WIN_W	768
 /**
 *  Window height size
 */
#define WIN_H	672

/**
 * @fn Sint32 window_init()
 * @return 0 if the audio initialization was succeeded
 * @brief Initializes Window SubSystem
 */
Sint32		window_init();

/**
 * @fn void window_destroy()
 * @return void
 * @brief Destroys Window SubSystem
 */
void		window_destroy();

/**
 * @fn SDL_Window *get_window()
 * @return a pointer on a SDL_Window struct
 * @brief Window getter
 */
SDL_Window	*get_window();

#endif /*! WINDOW_H */
