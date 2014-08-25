/*
** list.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Thu Jun 26 01:46:35 2014 AHAMADA Samir
** Last update Wed Jul 23 12:37:31 2014 ENNEBATI Yassine
*/

/**
 *	@file	base/list.c
 *	@brief	Linked lists
 */

#include <stdio.h>
#include "memory.h"

#include "list.h"

t_singlelist	*list_make_node()
{
  t_singlelist	*node;

  node = mem_alloc(1, sizeof(t_singlelist));
  node->data = NULL;
  node->next = NULL;
  node->index = 0;
  return (node);
}

void	list_push(void *data, t_singlelist **tail)
{
  if (!tail)
  {
    fprintf(stderr, "FATAL ERROR: NULL list node\n");
    return ;
  }
  (*tail)->next = list_make_node();
  (*tail)->next->index = (*tail)->index + 1;
  *tail = (*tail)->next;
  (*tail)->data = data;
}

void		*list_get(t_singlelist *root, Uint16 index)
{
  t_singlelist	*read;

  if (!root)
  {
    fprintf(stderr, "FATAL ERROR: NULL list node\n");
    return (NULL);
  }
  for (read = root; read; read = read->next)
    if (read->index == index)
      return (read->data);
  return (0);
}

Uint16		my_list_size(t_singlelist *root)
{
  t_singlelist	*read;
  Uint16	count;

  if (!root)
  {
    fprintf(stderr, "FATAL ERROR: NULL list node\n");
    return (0);
  }
  count = 0;
  for (read = root; read; read = read->next)
    ++count;
  return (count);
}

void		list_clear(t_singlelist **root)
{
  t_singlelist	*read;
  t_singlelist	*next;

  if (!root)
  {
    fprintf(stderr, "FATAL ERROR: NULL list node\n");
    return ;
  }
  next = NULL;
  for (read = *root; read; read = next)
  {
    next = read->next;
    mem_free(read);
  }
  *root = NULL;
}
