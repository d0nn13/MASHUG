/*
** alien.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Fri Apr 25 22:30:46 2014 AHAMADA Samir
** Last update Wed Jul 23 17:00:53 2014 ENNEBATI Yassine
*/

#ifndef GAMES_SPACEINVADERS_OBJECTS_ALIEN_H_
# define GAMES_SPACEINVADERS_OBJECTS_ALIEN_H_

# include <SDL2/SDL.h>
# include "../../../core/graphics.h"

/**
 *	@brief	Spaceinvaders alien structure definition
 */
typedef struct		s_spacealien
{
  void			(*display)(struct s_spacealien const *alien);
  void			(*move)(struct s_spacealien *alien);
  void			(*fire)();
  void			(*collide)();
  t_spriteholder const	*sprite;
  SDL_Rect 		rect;
}			t_spacealien;

/**
 *	@brief	Initializes Space Invaders alien
 */
void	space_init_alien(char const *sprite);

/**
 *	@brief	Alien getter
 */
t_spacealien	*get_spacealiens();

#endif /* !GAMES_SPACEINVADERS_ALIEN_H_ */
