/*
** core.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:32 2014 ENNEBATI Yassine
** Last update Tue Aug 12 22:05:40 2014 ENNEBATI Yassine
*/

/**
 *	@file	core.h
 *	@brief	Space Invaders Game!!
 */

#ifndef GAMES_SPACEINVADERS_CORE_H_
# define GAMES_SPACEINVADERS_CORE_H_

/**
 *	@brief	Main loop
 */
void	space_loop();

/**
 *	@brief	Space bounds getter
 */
SDL_Rect const	*get_spacebounds();

#endif /* !GAMES_SPACEINVADERS_CORE_H_ */
