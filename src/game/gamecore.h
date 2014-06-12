/*
** gamecore.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 16:01:40 2014 AHAMADA Samir
** Last update Sun May  4 13:03:08 2014 AHAMADA Samir
*/

/**
 *	Game!!
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
 */
Sint32	init_game();

/**
 *	Clears screen with color 'c' and renders cabinet
 */
void	redraw_context(SDL_Color *c);

/**
 *	Main loop
 */
void	game_loop();

/**
 *	Destroys Game
 */
void	destroy_game();

#endif /* !GAMECORE_H */
