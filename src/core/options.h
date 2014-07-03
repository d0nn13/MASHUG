/*
** options.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat Jun 28 20:01:00 2014 AHAMADA Samir
** Last update Thu Jul  3 14:19:06 2014 AHAMADA Samir
*/

/**
 *	@file	options.h
 *	@brief	Options handling
 */

#ifndef CORE_OPTIONS_H
# define CORE_OPTIONS_H

# include <SDL2/SDL_stdinc.h>

# define	KEY_MAX_LEN	16

typedef struct	s_optionholder
{
  char		key[KEY_MAX_LEN + 1];
  Sint16	value;
}		t_optionholder;

typedef enum
  {
    LOG_PRIO_OPT = 0,
    LOG_CAT_OPT,
    GAME_FPS_OPT,
    NB_OPT
  }		t_options;


void	options_init();

Sint16	get_option_value(t_options o);

void	set_option_value(t_options o, Sint16 v);

char	*get_option_key(t_options o);

void	options_debug();

#endif
