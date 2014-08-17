/*
** options.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat Jun 28 20:01:00 2014 AHAMADA Samir
** Last update Wed Jul 23 16:57:55 2014 ENNEBATI Yassine
*/

/**
 *	@file	options.h
 *	@brief	Options handling
 */

#ifndef CORE_OPTIONS_H_
# define CORE_OPTIONS_H_

# include <SDL2/SDL_stdinc.h>

# define KEY_MAX_LEN	16

typedef struct	s_optionholder
{
  char		key[KEY_MAX_LEN + 1];
  Sint16	value;
  Sint16	min;
  Sint16	max;
}		t_optionholder;

typedef enum
{
  LOG_PRIO_OPT = 0,
  VIDEO_DBG_OPT,
  FRAMERATE_OPT,
  NB_OPT
}	t_options;

void	options_init();

Sint16	get_option_value(t_options o);

Uint8	set_option_value(t_options o, Sint16 v);

char	*get_option_key(t_options o);

void	options_debug();

#endif /* !CORE_OPTIONS_H_ */
