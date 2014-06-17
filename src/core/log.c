/*
** log.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 14:06:14 2014 AHAMADA Samir
** Last update Sat May  3 17:11:06 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <time.h>
#include <SDL2/SDL_log.h>
#include "log.h"

static char	timestr[9];

/**
 * Beware of the order! See macro and enum in log.h
 */
static char	*catstrings[NB_LCAT] = 
{
  "",
  "Space Invaders",
  "Error",
  "System",
  "Audio",
  "Video",
  "Render",
  "Input",
  "Graphics",
  "Sprites",
  "Fonts"
};

/**
 *	Writes a timestamp into 'timestr'
 */
static void	timestamp();

/**
 *	Prints the timestamp written in 'timestr'
 */
static void	log_print(void *userdata, int cat, SDL_LogPriority p, const char *msg);

/* Log priority settings are temporary */
void	log_init()
{
  SDL_LogSetOutputFunction(&log_print, NULL);
#ifdef VERBOSE
  SDL_LogSetAllPriority(0);
#else
  SDL_LogSetPriority(AUD_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(VID_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(RDR_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(GFX_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(SPR_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(INP_LCAT, SDL_LOG_PRIORITY_INFO);
#endif
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

static void	log_print(void *userdata, int cat, SDL_LogPriority p, const char *msg)
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
