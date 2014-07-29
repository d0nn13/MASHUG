/*
** helpers.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Wed Jul 09 21:50:17 2014 Samir Ahamada
** Last update Wed Jul 23 13:27:26 2014 ENNEBATI Yassine
*/

/**
 *	@file	helpers.h
 *	@brief	Convinient helping functions
 */

#include "../base/memory.h"

#include "helpers.h"

SDL_Rect	rect_factory(int const x, int const y, int const w, int const h)
{
  SDL_Rect	newrect;

  newrect.x = x;
  newrect.y = y;
  newrect.w = w;
  newrect.h = h;
  return (newrect);
}

SDL_Point	point_factory(int const x, int const y)
{
  SDL_Point	newpoint;

  newpoint.x = x;
  newpoint.y = y;
  return (newpoint);
}

SDL_Color	color_factory(Uint8 const r,
			      Uint8 const g,
			      Uint8 const b,
			      Uint8 const a)
{
  SDL_Color	newcolor;

  newcolor.r = r;
  newcolor.g = g;
  newcolor.b = b;
  newcolor.a = a;
  return (newcolor);
}

Sint32	key_filter(void *userdata, SDL_Event *event)
{
  userdata = (void *)userdata;
  if (event->type != SDL_KEYDOWN && event->type != SDL_QUIT)
    return (0);
  if (event->type == SDL_KEYDOWN)
    if (event->key.keysym.scancode != UP && event->key.keysym.scancode != DN &&
  	event->key.keysym.scancode != SDL_SCANCODE_ESCAPE &&
  	event->key.keysym.scancode != SDL_SCANCODE_RETURN &&
  	event->key.keysym.scancode != SDL_SCANCODE_KP_ENTER)
      return (0);
  return (1);
}

char		**file_to_tab(char const *path)
{
  FILE		*file_in;
  char		*line;
  size_t	len;
  Uint32	nb_lines;
  char		**file_parse;

  line = mem_alloc(sizeof(char *));
  len = 0;
  nb_lines = 0;
  if ((file_in = fopen(path, "r")) == NULL)
    return (NULL);
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
