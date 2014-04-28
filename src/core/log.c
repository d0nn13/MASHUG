/*
** log.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 14:06:14 2014 AHAMADA Samir
** Last update Mon Apr 28 16:18:20 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <time.h>
#include <SDL2/SDL_log.h>
#include "log.h"

static char	timestr[9];
static char	*catstrings[LAST_LCAT];
static void	timestamp();
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
  SDL_LogSetPriority(SPR_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(FNT_LCAT, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(INP_LCAT, SDL_LOG_PRIORITY_INFO);
#endif
  catstrings[APP_LCAT] = "Space Invaders";
  catstrings[ERR_LCAT] = "Error";
  catstrings[SYS_LCAT] = "System";
  catstrings[AUD_LCAT] = "Audio";
  catstrings[VID_LCAT] = "Video";
  catstrings[RDR_LCAT] = "Render";
  catstrings[INP_LCAT] = "Input";
  catstrings[SPR_LCAT] = "Sprites";
  catstrings[FNT_LCAT] = "Fonts";
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
