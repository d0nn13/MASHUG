/*
** block.h for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 04:01:44 2014 ENNEBATI Yassine
** Last update Sun Aug 10 04:08:06 2014 ENNEBATI Yassine
*/

/**
 *	@file	block.h
 *	@brief	Space Invaders block definition
 */

#ifndef	GAMES_SPACEINVADERS_OBJECT_BLOCK_H_
# define GAMES_SPACEINVADERS_OBJECT_BLOCK_H_

# include <SDL2/SDL.h>
# include "../../../base/list.h"
# include "../../../core/graphics.h"

#define NB_SPACE_BLOCK_SPR	2

/**
 *	@brief	Spaceinvaders block structure definition
 */
typedef struct		s_spaceblock
{
  void			(*display)(t_singlelist *block);
  void			(*collide)();
  t_spriteholder const	*sprite[NB_SPACE_BLOCK_SPR];
  SDL_Rect 		rect;
}			t_spaceblock;

/**
 *	@brief	Initializes Space Invaders block
 */
void	spaceblock_init();

/**
 *	@brief	Destroys Space Invaders block
 */
void	spaceblock_destroy();

/**
 *	@brief	Block getter
 */
t_singlelist	*get_spaceblocks();





#endif /* !GAMES_SPACEINVADERS_OBJECT_BLOCK_H_ */
