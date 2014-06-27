/*
** window.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 20 22:08:12 2014 AHAMADA Samir
** Last update Thu Jun 26 17:16:55 2014 AHAMADA Samir
*/

/**
 *	@file	window.h
 *	@brief	Window handling engine
 */

#ifndef CORE_WINDOW_H
# define CORE_WINDOW_H

# include <SDL2/SDL_video.h>

/**
 *	Window weight size
 */
# define WIN_W	768
 /**
 *	Window height size
 */
# define WIN_H	672

/**
 *	@brief	Initializes Window SubSystem
 *
 *	@return	0 if the audio initialization was succeeded
 *	@return -1 if the audio initialization failed
 */
Sint32		window_init();

/**
 *	@brief	Destroys Window SubSystem
 */
void		window_destroy();

/**
 *	@brief	Window getter
 *
 *	@return	a pointer to the engine's SDL_Window struct
 */
SDL_Window	*get_window();

#endif /* !CORE_WINDOW_H */
