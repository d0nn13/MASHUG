/*
** options.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat Jun 28 20:14:00 2014 AHAMADA Samir
** Last update Sun Jun 29 23:54:18 2014 AHAMADA Samir
*/

/**
 *	@file	options.c
 *	@brief	Options handling
 */

#include <string.h>
#include <stdio.h>

#include "options.h"

static t_optionholder	options[NB_OPT] = {
  {"Log Priority", -1},
  {"Log Category", -1},
  {"Game Framerate", -1},
};

Sint16	get_option_value(t_options o)
{
  if (o >= NB_OPT)
    {
      printf("get_option_value: option <%d> is out of boundary\n", o);
      return (-1);
    }
  return (options[o].value);
}

void	set_option_value(t_options o, Sint16 v)
{
  if (o >= NB_OPT)
    printf("set_option_value: option <%d> is out of boundary\n", o);
  else
    options[o].value = v; 
}

char	*get_option_key(t_options o)
{
  if (o >= NB_OPT)
    {
      printf("get_option_key: option <%d> is out of boundary\n", o);
      return (NULL);
    }
  return (options[o].key);
}
