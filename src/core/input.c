/*
** input.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Aug 04 16:46:28 2014 Samir Ahamada
** Last update Sat Sep  6 13:22:33 2014 ENNEBATI Yassine
*/

/**
 *	@file	input.c
 *	@brief	Input engine
 */

#include <SDL2/SDL_events.h>
#include "log.h"

#include "input.h"

static t_inputholder input[NB_INP] = {
  {SDL_SCANCODE_RETURN, 0, "START"},
  {SDL_SCANCODE_ESCAPE, 0, "RETURN"},
  {SDL_SCANCODE_UP, 0, "UP"},
  {SDL_SCANCODE_LEFT, 0, "LEFT"},
  {SDL_SCANCODE_DOWN, 0, "DOWN"},
  {SDL_SCANCODE_RIGHT, 0, "RIGHT"},
  {SDL_SCANCODE_SPACE, 0, "FIRE"},
  {0, 0, "BUTTON2"},
  {SDL_SCANCODE_I, 0, "TEST"},
  {SDL_SCANCODE_G, 0, "GAMEOVER_TEST"}
};

void	input_update()
{
  Uint8	i;

  SDL_PumpEvents();
  for (i = 0; i < NB_INP; ++i)
    input[i].state = SDL_GetKeyboardState(NULL)[input[i].code];
}

void	input_flush()
{
  Uint8	i;

  for (i = 0; i < NB_INP; ++i)
    input[i].state = 0;
}

t_inputholder	*get_input(t_inputs i)
{
  return (&input[i]);
}

Sint32	key_filter(void *userdata, SDL_Event *event)
{
  userdata = (void *)userdata;
  if (event->type != SDL_KEYDOWN && event->type != SDL_QUIT)
    return (0);
  return (1);
}

