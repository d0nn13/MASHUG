/*
** file_helpers.c for helpers in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG/xml/src/core/helpers
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Tue Jul 29 12:35:39 2014 Samir Ahamada
** Last update Tue Jul 29 12:35:39 2014 Samir Ahamada
*/

/**
 *	@file	file_helpers.c
 *	@brief	Convinient file helping functions
 */

#ifdef __linux__
# define _GNU_SOURCE
#endif
#include "../../base/memory.h"

#include "../helpers.h"

char		**file_to_tab(char const *path)
{
  FILE		*file_in;
  char		*line;
  size_t	len;
  Uint16	nb_lines;
  char		**file_parse;

  len = 0;
  nb_lines = 0;
  if ((file_in = fopen(path, "r")) == NULL)
    return (NULL);
  line = mem_alloc(sizeof(char *));
  while (getline(&line, &len, file_in) != -1)
    nb_lines++;
  fseek(file_in, 0, SEEK_SET);
  file_parse = mem_alloc(sizeof(char *) * (nb_lines + 1));
  for (nb_lines = 0; getline(&line, &len, file_in) != -1; ++nb_lines)
  {
    file_parse[nb_lines] = mem_alloc(sizeof(char) * (strlen(line) + 1));
    file_parse[nb_lines] = strcpy(file_parse[nb_lines], line);
  }
  mem_free(line);
  fclose(file_in);
  return (file_parse);
}

void		free_filetab(char **filetab)
{
  Uint16	i;

  for (i = 0; filetab[i]; ++i)
    mem_free(filetab[i]);
  mem_free(filetab);
}
