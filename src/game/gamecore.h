/*
** gamecore.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 16:01:40 2014 AHAMADA Samir
** Last update Sat May  3 20:18:36 2014 AHAMADA Samir
*/

/**
 *	Game context management
 */

#ifndef GAMECORE_H
#define GAMECORE_H

#include "menu.h"

/**
 *	Initializes Game (load sprites, draw UI etc...)
 */
Sint32	init_game();

/**
 *	Destroys Game
 */
void	destroy_game();

#endif /* !GAMECORE_H */
