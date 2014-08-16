/*
** log.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 21 14:06:14 2014 AHAMADA Samir
** Last update Wed Jul 23 15:16:45 2014 ENNEBATI Yassine
*/

/**
 *	@file	log.c
 *	@brief	Log engine
 */

#include <stdio.h>
#include <time.h>
#include <SDL2/SDL_log.h>

#include "log.h"

/**
 *	@brief String containing timestamp (internal)
 */
static char	timestr[9];

/**
 *	@brief Log categories string array (internal)
 */
static char	*catstrings[NB_LCAT] = {
  "MASHUG",
  "Error",
  NULL,
  "System",
  "Audio",
  "Video",
  "Render",
  "Input",
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  "Graphics",
  "Sprites",
  "Fonts",
  "Options",
  "XML"
};

/**
 *	@brief Writes a timestamp into 'timestr' (internal)
 */
static void	timestamp();

/**
 *	@brief Log printing callback (internal)
 */
static void	log_print(void *userdata,
			  int cat,
			  SDL_LogPriority p,
			  char const *msg);

/* Log priority settings are temporary */
void	log_init()
{
  SDL_LogSetOutputFunction(&log_print, NULL);
  SDL_LogSetPriority(OPT_LCAT, SDL_LOG_PRIORITY_DEBUG);
}

void	log_set_all_priority(SDL_LogPriority priority)
{
  Uint8	c;

  SDL_LogSetAllPriority(priority);
  for (c = SDL_LOG_CATEGORY_CUSTOM; c < NB_LCAT; ++c)
    SDL_LogSetPriority(c, priority);
  if (priority)
    SDL_LogSetPriority(SDL_LOG_CATEGORY_ERROR, 7);
}

Uint8	ptr_chk(void const *p, char const *psym, Uint32 cat, char const *fsym)
{
  if (!p)
  {
    SDL_LogError(cat, "%s: NULL pointer detected > %s <", fsym, psym);
    return (0);
  }
  return (1);
}

static void	timestamp()
{
  time_t	t;

  time(&t);
  sprintf(timestr, "%02d:%02d:%02d",
	  localtime(&t)->tm_hour,
	  localtime(&t)->tm_min,
	  localtime(&t)->tm_sec);
}

static void	log_print(void *userdata,
			  int cat,
			  SDL_LogPriority p,
			  char const *msg)
{
  userdata = (void *)userdata;
  timestamp();
  if (p < SDL_LOG_PRIORITY_ERROR)
    printf("\x1b[1;0m%s [\x1b[1;33m%s\x1b[1;0;0m] %s\x1b[0;0;0m\n",
	   timestr, catstrings[cat], msg);
  else
    printf("\x1b[1;0;41m%s [\x1b[1;33;41m%s\x1b[1;0;41m] %s\x1b[0;0;0m\n",
	   timestr, catstrings[cat], msg);
}
