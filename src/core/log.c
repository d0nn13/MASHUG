/*
** log.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 14:06:14 2014 AHAMADA Samir
** Last update Mon Apr 21 16:05:10 2014 AHAMADA Samir
*/

#include <stdio.h>
#include <time.h>
#include "log.h"

static char	timestr[9];

static void		timestamp()
{
  time_t	t;
  time(&t);
  sprintf(timestr, "%02d:%02d:%02d",
	  localtime(&t)->tm_hour,
	  localtime(&t)->tm_min,
	  localtime(&t)->tm_sec);
}

int	print_log(const char *sender, const char *msg1, const char* msg2)
{
  timestamp();
  if (!msg2)
    printf("\x1b[0;0;0m%s [\x1b[0;33;40m%s\x1b[0;0;0m] %s\n",
	   timestr, sender, msg1);
  else
    printf("\x1b[0;0;0m%s [\x1b[0;33;40m%s\x1b[0;0;0m] %s : %s\n",
	   timestr, sender, msg1, msg2);
  return (0);
}

int	print_error(const char *sender, const char *msg1, const char* msg2)
{
  timestamp();
  if (!msg2)
  printf("\x1b[1;0;41m[\x1b[1;33;41m%s\x1b[1;0;41m] ERROR : %s\x1b[0;0;0m\n",
	 sender, msg1);
else
  printf("\x1b[1;0;41m[\x1b[1;33;41m%s\x1b[1;0;41m] ERROR : %s : %s\x1b[0;0;0m\n",
	 sender, msg1, msg2);
  return (1);
}
