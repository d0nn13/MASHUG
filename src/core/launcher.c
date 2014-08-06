/*
** launcher.c for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG/master/src/core
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Aug 06 13:06:27 2014 Samir Ahamada
** Last update Wed Aug 06 13:06:27 2014 Samir Ahamada
*/

#include "launcher.h"

static t_exec	launcher;

t_exec	get_launcher()
{
  return (launcher);
}

void	set_launcher(t_exec x)
{
  launcher = x;
}
