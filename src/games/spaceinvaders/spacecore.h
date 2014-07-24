/*
** spacecore.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:32 2014 ENNEBATI Yassine
** Last update Tue Jul 15 13:14:35 2014 ENNEBATI Yassine
*/

/**
 *	@file	spacecore.h
 *	@brief	Space Invaders Game!!
 */

#ifndef GAMES_SPACEINVADERS_SPACECORE_H_
# define GAMES_SPACEINVADERS_SPACECORE_H_

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
void	redraw_context(SDL_Color const *c);

/**
 *	@brief	Main loop
 */
void	space_loop();

/**
 *	@brief	Destroys Space Invaders game (free all stuff was allocated...)
 */
void	space_destroy();

#endif /* !GAMES_SPACEINVADERS_SPACECORE_H_ */
