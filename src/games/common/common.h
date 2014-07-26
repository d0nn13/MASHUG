/*
** common.h for  in /Users/Yassine/Code/ETNA/projet/c/mashug/src
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Fri Jul 25 16:42:38 2014 ENNEBATI Yassine
** Last update Sat Jul 26 15:57:10 2014 ENNEBATI Yassine
*/

/**
 *	@file	common.h
 *	@brief	Common game init
 */

#ifndef GAMES_COMMON_COMMON_H_
# define GAMES_COMMON_COMMON_H_

/**
 *	@brief	Initializes common stuff for each games (sfx, fonts)
 */
Sint32	common_init();

/**
 *	@brief	Destroys common stuff for each games initialized (sfx, fonts)
 */
void	common_destroy();

#endif /* !GAMES_COMMON_COMMON_H_ */
