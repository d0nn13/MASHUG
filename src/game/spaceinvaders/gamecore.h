/*
** gamecore.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 16:01:40 2014 AHAMADA Samir
** Last update Wed Jul  9 12:10:02 2014 ENNEBATI Yassine
*/

/**
 *	@file	gamecore.h
 *	@brief	Game!!
 */

#ifndef GAME_GAMECORE_H
# define GAME_GAMECORE_H

/**
 *	@brief	Game mode callback definition
 */
typedef void	(*t_mode)();

/**
 *	@brief	Global callback
 */
extern	t_mode	g_launcher;


/**
 *	@brief	Initializes Game (load sprites, draw UI etc...)
 *	@return	0 on success, -1 on any error
 */
Sint32	game_init();

/**
 *	@brief	Clears screen with color 'c' and renders cabinet
 *	@param	c The color to clear the screen with
 */
void	redraw_context(const SDL_Color *c);

/**
 *	@brief	Main loop
 */
void	game_loop();

/**
 *	@brief	Destroys Game (free all stuff was allocated...)
 */
void	game_destroy();

#endif /* !GAME_GAMECORE_H */
