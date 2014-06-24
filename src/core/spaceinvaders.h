/*
** spaceinvaders.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Wed Apr 23 01:41:36 2014 AHAMADA Samir
** Last update Tue Jun 24 18:12:12 2014 AHAMADA Samir
*/

/**
 *	@file	spaceinvaders.h
 *	@brief	Main game file
 */

#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

/**
 *	@brief	Initializes engine modules
 *
 *	@return	0 if all initializations are succeded
 *	@return -1 if a module initialization failed
 */
Sint32	init_core();

/**
 *	@brief	Destroys all engine modules
 *
 *	@return	0
 */
Sint32	destroy_core();

#endif /* !SPACEINVADERS_H */
