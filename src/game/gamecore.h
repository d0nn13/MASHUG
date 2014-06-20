/*
** gamecore.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 16:01:40 2014 AHAMADA Samir
** Last update Sat Jun 21 01:05:10 2014 ENNEBATI Yassine
*/

/**
 *	@file	gamecore.h
 *	@brief	Game!!
 */

#ifndef GAMECORE_H
#define GAMECORE_H

/**
 *	Game mode callback definition
 */
typedef void	(*t_mode)();

/**
 *	Global callback
 */
extern	t_mode	g_launcher;


/**
 *	Initializes Game (load sprites, draw UI etc...)
 *	@return 0 on success, -1 on any error 
 */
Sint32	init_game();

/**
 *	Clears screen with color 'c' and renders cabinet
 *	@param c The color to clear the screen with
 */
void	redraw_context(SDL_Color *c);

/**
 *	Main loop
 */
void	game_loop();

/**
 *	Destroys Game (free all stuff was allocated...)
 */
void	destroy_game();

#endif /* !GAMECORE_H */
