/*
** log.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 14:06:14 2014 AHAMADA Samir
** Last update Tue Apr 22 11:53:39 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <time.h>
#include <SDL2/SDL_log.h>
#include "log.h"

enum {
  SPACE_CATEGORY_CUSTOM1 = SDL_LOG_CATEGORY_CUSTOM,
  SPACE_CATEGORY_CUSTOM2
};

static char	timestr[9];
static char	*catstrings[SPACE_CATEGORY_CUSTOM2 + 1];
static void	timestamp();
static void	print_log(void *userdata, int cat, SDL_LogPriority p, const char *msg);

/* Log priority settings are temporary */
void	Log_init()
{
  SDL_LogSetOutputFunction(&print_log, NULL);
  SDL_LogSetPriority(SDL_LOG_CATEGORY_AUDIO, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(SDL_LOG_CATEGORY_VIDEO, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_INFO);
  SDL_LogSetPriority(SDL_LOG_CATEGORY_INPUT, SDL_LOG_PRIORITY_INFO);
  catstrings[SDL_LOG_CATEGORY_APPLICATION] = "Space Invaders";
  catstrings[SDL_LOG_CATEGORY_ERROR] = "Error";
  catstrings[SDL_LOG_CATEGORY_SYSTEM] = "System";
  catstrings[SDL_LOG_CATEGORY_AUDIO] = "Audio";
  catstrings[SDL_LOG_CATEGORY_VIDEO] = "Video";
  catstrings[SDL_LOG_CATEGORY_RENDER] = "Render";
  catstrings[SDL_LOG_CATEGORY_INPUT] = "Input";
  catstrings[SPACE_CATEGORY_CUSTOM1] = "Custom One";
  catstrings[SPACE_CATEGORY_CUSTOM2] = "Custom Two";
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

static void	print_log(void *userdata, int cat, SDL_LogPriority p, const char *msg)
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
