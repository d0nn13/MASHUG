/*
** gamecore.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 16:01:40 2014 AHAMADA Samir
** Last update Tue Apr 29 17:38:03 2014 AHAMADA Samir
*/

#ifndef GAMECORE_H
#define GAMECORE_H

/**
 *	Initializes Game (load sprites, draw UI etc...)
 */
Sint32	init_game();

/**
 *	Main menu
 */
Sint32	menu_game();

/**
 *	Destroys Game
 */
void	destroy_game();

#endif /* !GAMECORE_H */
