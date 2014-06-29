/*
** optionscli.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Jun 29 13:44:07 2014 AHAMADA Samir
** Last update Sun Jun 29 23:44:49 2014 AHAMADA Samir
*/

/**
 *	@file	optionscli.c
 *	@brief	CLI options handling
 */

#include <stdlib.h>
#include <getopt.h>
#include "log.h"
#include "options.h"

#include "optionscli.h"

static struct option optionscli[NB_OPT + 1] = {
  {"log-priority", required_argument, NULL, LOG_PRIO_OPT},	/* short : none */
  {"log-category", required_argument, NULL, LOG_CAT_OPT},	/* short : none */
  {"framerate", required_argument, NULL, GAME_FPS_OPT},		/* short : -f   */
  {NULL, 0, NULL, 0}
};

Uint8	set_options_from_cli(int argc, char **argv)
{
  Sint8	o;

  while ((o = getopt_long(argc, argv, "f:", optionscli, NULL)) != -1)
    {
      if (o != '?')
	{
	  SDL_Log("set_options_from_cli: [%d] <- %s\n", o, optarg ? optarg : "NONE");
	  set_option_value(o, atoi(optarg));
	}
    }
  return (0);
}
