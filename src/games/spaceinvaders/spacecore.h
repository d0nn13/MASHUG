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
 *	@brief	Clears screen with color 'c' and renders cabinet
 *	@param	c The color to clear the screen with
 */
void	space_redraw_context(SDL_Color const *c);

/**
 *	@brief	Main loop
 */
void	space_loop();

#endif /* !GAMES_SPACEINVADERS_SPACECORE_H_ */
