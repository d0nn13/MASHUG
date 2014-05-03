/*
** spaceinvaders.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Apr 23 01:41:36 2014 AHAMADA Samir
** Last update Sat May  3 22:15:52 2014 AHAMADA Samir
*/

#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

/**
 *	Initializes Core
 */
Sint32	init_core();

/**
 *	Destroys Core
 */
Sint32	destroy_core();

/**
 *	Main loop
 */
void	game_loop(void (*launch)());

#endif /* !SPACEINVADERS_H */
