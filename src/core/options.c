/*
** options.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sat Jun 28 20:14:00 2014 AHAMADA Samir
** Last update Sun Jun 29 09:31:03 2014 AHAMADA Samir
*/

/**
 *	@file	options.c
 *	@brief	Options handling
 */

#include <string.h>
#include <stdio.h>

#include "options.h"

static t_optionholder	options[NB_OPT];

void	options_init()
{
  Uint8	i;

  for (i = 0; i < NB_OPT; ++i)
    options[i].value = 0;
  strncpy(options[LOG_PRIO_OPT].key, "Log Priority Lvl", KEY_MAX_LEN);
  strncpy(options[LOG_CAT_OPT].key, "Log category Lvl", KEY_MAX_LEN);
  strncpy(options[GAME_FPS_OPT].key, "Game speed (FPS)", KEY_MAX_LEN);
}

Sint16	get_option_value(t_option o)
{
  if (o < 0 || o >= NB_OPT)
    printf("get_option_value: option <%d> is out of boundary\n", o);
  else
    return (options[o].value);
}

void	set_option_value(t_options o, Sint16 v)
{
  if (o < 0 || o >= NB_OPT)
    printf("set_option_value: option <%d> is out of boundary\n", o);
  else
    options[o].value = v; 
}

char	*get_option_key(t_options o)
{
  if (o < 0 || o >= NB_OPT)
    printf("get_option_key: option <%d> is out of boundary\n", o);
  else
    return (options[o].key);
}
