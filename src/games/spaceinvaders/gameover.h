/*
** gameover.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Sep  7 18:58:37 2014 ENNEBATI Yassine
** Last update Sun Sep  7 18:58:53 2014 ENNEBATI Yassine
*/

/**
 *	@file	gameover.h
 *	@brief	Game over for space invaders game
 */

#ifndef GAMES_SPACEINVADERS_GAMEOVER_H_
# define GAMES_SPACEINVADERS_GAMEOVER_H_

# define	NB_LETTER 5

typedef struct	s_letter
{
  char		letter;
  SDL_Color	sel_color;
  SDL_Color	uns_color;
}		t_letter;

void	space_gameover();

#endif /* !GAMES_SPACEINVADERS_GAMEOVER_H_ */
