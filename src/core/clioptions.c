/*
** clioptions.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Jun 29 13:44:07 2014 AHAMADA Samir
** Last update Mon Jun 30 13:09:57 2014 AHAMADA Samir
*/

/**
 *	@file	clioptions.c
 *	@brief	CLI options handling
 */

#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "log.h"
#include "options.h"

#include "clioptions.h"

static struct option clioptions[NB_OPT + 1] = {
  {"log-priority", required_argument, NULL, LOG_PRIO_OPT},
  {"log-category", required_argument, NULL, LOG_CAT_OPT},
  {"framerate", required_argument, NULL, GAME_FPS_OPT},
  {NULL, 0, NULL, 0}
};

void		set_options_from_cli(int argc, char **argv)
{
  Sint8		o;
  Sint16	v;

  opterr = 0;
  while ((o = getopt_long(argc, argv, "", clioptions, NULL)) != -1)
    {
      if (o == '?')
	SDL_LogError(OPT_LCAT, "Unrecognized option '%s'", argv[optind - 1]);
      else
	{
	  v = optarg ? strtol(optarg, NULL, 10) : 1;
	  if (optarg && (errno == EINVAL || errno == ERANGE))
	    {
	      SDL_LogError(OPT_LCAT, "Uncorrect value '%s' for option '%s'", optarg,
			   get_option_key(o));
	      errno = 0;
	      continue ;
	    }
	  SDL_LogInfo(OPT_LCAT, "[%s] <- %d\n", get_option_key(o), v);
	  set_option_value(o, v);
	}
    }
}
