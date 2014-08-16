/*
** options.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat Jun 28 20:14:00 2014 AHAMADA Samir
** Last update Mon Jul 14 02:08:03 2014 ENNEBATI Yassine
*/

/**
 *	@file	options.c
 *	@brief	Options handling
 */

#include "../base/math.h"
#include "log.h"

#include "options.h"

/**
 *	@brief	Default settings definition
 */
static t_optionholder	options[NB_OPT] = {
  {"Log Priority", 3, 0, 6},
  {"Log Category", -1, 0, 0},
  {"Game Framerate", 60, 1, 100},
};

Sint16	get_option_value(t_options o)
{
  if (o >= NB_OPT)
  {
    SDL_LogError(OPT_LCAT,
		 "get_option_value: option <%d> is out of boundary\n", o);
    return (-1);
  }
  return (options[o].value);
}

Uint8	set_option_value(t_options o, Sint16 v)
{
  if (!IS_BELOW(o, NB_OPT))
  {
    SDL_LogError(OPT_LCAT,
		 "set_option_value: option <%d> is out of boundary\n", o);
    return (0);
  }
  if (!IN_RANGE(v, options[o].min, options[o].max))
  {
    SDL_LogError(OPT_LCAT,
		 "set_option_value: value '%d' is out of boundary", v);
    return (0);
  }
  options[o].value = v;
  return (1);
}

char	*get_option_key(t_options o)
{
  if (o >= NB_OPT)
  {
    SDL_LogError(OPT_LCAT,
		 "get_option_key: option <%d> is out of boundary\n", o);
    return (NULL);
  }
  return (options[o].key);
}

void	options_debug()
{
  Uint8	i;

  SDL_LogSetPriority(OPT_LCAT, get_option_value(LOG_PRIO_OPT));
  for (i = 0; i < NB_OPT; ++i)
    SDL_LogVerbose(OPT_LCAT, "Debug: <%s> '%d'", get_option_key(i),
		   get_option_value(i));
}
