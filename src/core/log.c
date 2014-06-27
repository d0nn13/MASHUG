/*
** log.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 21 14:06:14 2014 AHAMADA Samir
** Last update Fri Jun 27 15:30:29 2014 AHAMADA Samir
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
static char	*catstrings[NB_LCAT];

/**
 *	@brief Writes a timestamp into 'timestr' (internal)
 */
static void timestamp();

/**
 *	@brief Log printing callback (internal)
 */
static void log_print(void *userdata, int cat, SDL_LogPriority p, const char *msg);


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
  catstrings[APP_LCAT] = "Space Invaders";
  catstrings[ERR_LCAT] = "Error";
  catstrings[SYS_LCAT] = "System";
  catstrings[AUD_LCAT] = "Audio";
  catstrings[VID_LCAT] = "Video";
  catstrings[RDR_LCAT] = "Render";
  catstrings[INP_LCAT] = "Input";
  catstrings[GFX_LCAT] = "Graphics";
  catstrings[SPR_LCAT] = "Sprites";
  catstrings[FNT_LCAT] = "Fonts";
}

Uint8	ptr_chk(const void *p, const char *psym, Uint32 cat, const char *fsym)
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
