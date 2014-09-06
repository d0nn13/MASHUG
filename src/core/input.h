/*
** input.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Aug 04 14:59:07 2014 Samir Ahamada
** Last update Sat Sep  6 13:22:26 2014 ENNEBATI Yassine
*/

/**
 *	@file	input.h
 *	@brief	Input engine
 */

#ifndef CORE_INPUT_H_
# define CORE_INPUT_H_

# include <SDL2/SDL_events.h>

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
  GAMEOVER_TEST_INP,
  NB_INP
}		t_inputs;

/**
 *	@brief	Updates internal input state
 */
void	input_update();

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

#endif /* CORE_INPUT_H_ */
