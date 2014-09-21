/*
** ufo.h for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 12:11:14 2014 FOFANA Ibrahim
** Last update Sun Sep 21 20:02:04 2014 FOFANA Ibrahim
*/

/**
 *	@file ufo.h
 *	@brief	Spaceinvaders ufo structure definition
 */

#ifndef GAMES_SPACEINVADERS_OBJECTS_UFO_H__
# define GAMES_SPACEINVADERS_OBJECTS_UFO_H__

# include <SDL2/SDL.h>
# include "../../../core/graphics.h"

typedef enum
{
  UFO_NONE = 0,
  UFO_LEFT,
  UFO_RIGHT
}		t_ufo_direction;

typedef struct		s_spaceufo
{
  void			(*display)(struct s_spaceufo const *ufo);
  void			(*move)(struct s_spaceufo *ufo);
  t_spriteholder const	*sprite;
  SDL_Rect		rect;
  Sint32		score_gain;
  Sint32		alive;
  t_ufo_direction	direction;
}			t_spaceufo;

/**
 *	@brief	Initializes Space Invaders ufo
 */
t_spaceufo	*spaceufo_init();

/**
 *	@brief	Destroys Space Invaders ufo
 */
void	spaceufo_destroy(t_spaceufo **ufo);


#endif /* !GAMES_SPACEINVADERS_OBJECTS_UFO_H__ */
