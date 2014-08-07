/*
** input.h for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Aug 04 14:59:07 2014 Samir Ahamada
** Last update Mon Aug 04 14:59:07 2014 Samir Ahamada
*/

#ifndef CORE_INPUT_H
# define CORE_INPUT_H

#include <SDL2/SDL_events.h>

/* TODO: Removes these directives when game menus are up-to-date */
#define UP SDL_SCANCODE_UP
#define DN SDL_SCANCODE_DOWN

typedef	struct	s_inputholder
{
  SDL_Scancode	code;
  Uint8		state;
  char const	*key;
}		t_inputholder;

typedef	enum
{
  START_INP,
  RETURN_INP,
  UP_INP,
  LEFT_INP,
  DOWN_INP,
  RIGHT_INP,
  FIRE_INP,
  BUTTON2_INP,
  TEST_INP,
  NB_INP
}		t_inputs;

/**
 *	@brief	Updates internal input state
 */
void	input_update(Uint8 const *all);

/**
 *	@brief	Clears internal input state
 */
void	input_flush();

/**
 *	@brief	Input getter
 */
t_inputholder	*get_input(t_inputs i);

/**
 *	@brief	Keyboard event filter
 */
Sint32	key_filter(void *userdata, SDL_Event *event);

#endif /* CORE_INPUT_H */
