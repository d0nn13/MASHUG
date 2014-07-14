/*
** gamecore.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 16:01:40 2014 AHAMADA Samir
** Last update Mon Jul 14 13:35:26 2014 ENNEBATI Yassine
*/

/**
 *	@file	spacecore.h
 *	@brief	Space Invaders Game!!
 */

#ifndef GAMES_SPACEINVADERS_SPACECORE_H
# define GAMES_SPACEINVADERS_SPACECORE_H

/**
 *	@brief	Game mode callback definition
 */
typedef void	(*t_mode)();

/**
 *	@brief	Global callback
 */
extern	t_mode	g_launcher;


/**
 *	@brief	Initializes Space Invaders game (load sprites, draw UI etc...)
 *	@return	0 on success, -1 on any error
 */
Sint32	space_init();

/**
 *	@brief	Clears screen with color 'c' and renders cabinet
 *	@param	c The color to clear the screen with
 */
void	redraw_context(const SDL_Color *c);

/**
 *	@brief	Main loop
 */
void	space_loop();

/**
 *	@brief	Destroys Space Invaders game (free all stuff was allocated...)
 */
void	space_destroy();

#endif /* !GAMES_SPACEINVADERS_SPACECORE_H */
