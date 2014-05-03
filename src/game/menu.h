/*
** menu.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Apr 29 14:21:45 2014 AHAMADA Samir
** Last update Sat May  3 20:11:02 2014 AHAMADA Samir
*/

/**
 *	Main menu
 */

#ifndef	MENU_H
#define MENU_H

#include <SDL2/SDL_stdinc.h>

/**
 *	Main menu routine
 */
typedef void	(*mode)();
mode	menu_game();

#endif /* !MENU_H */
