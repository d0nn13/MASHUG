/*
** core_process.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:11:32 2014 ENNEBATI Yassine
** Last update Sat Sep  6 17:16:35 2014 ENNEBATI Yassine
*/

/**
 *	@file	core_process.h
 *	@brief	Space Invaders core processing
 */

#ifndef GAMES_SPACEINVADERS_CORE_PROCESS_H_
# define GAMES_SPACEINVADERS_CORE_PROCESS_H_

# include "core.h"

/**
 *	@brief	Space Invaders Events processing
 */
Uint8	space_process_events();

/**
 *	@brief	Space Invaders Objects processing
 */
void	space_process_objects(t_spaceobjects *o);

#endif /* !GAMES_SPACEINVADERS_CORE_PROCESS_H_ */
