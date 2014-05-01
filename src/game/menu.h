/*
** menu.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Apr 29 14:21:45 2014 AHAMADA Samir
** Last update Thu May  1 14:43:13 2014 AHAMADA Samir
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
Sint32		menu_game();

/**
 *	Menu displayer
 *	/!\ buggy, this will be redesigned when
 *	texture streaming will be implemented
 */
void		display_menu();

#endif /* !MENU_H */
