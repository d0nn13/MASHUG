/*
** list.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jun 26 01:46:35 2014 AHAMADA Samir
** Last update Fri Jul  4 20:48:54 2014 AHAMADA Samir
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

  node = mem_alloc(sizeof(t_singlelist));
  node->data = NULL;
  node->next = NULL;
  node->index = 0;
  return (node);
}

void		list_push(void *data, t_singlelist **tail)
{
  if (!tail)
    {
      printf("FATAL ERROR: NULL list node\n");
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
      printf("FATAL ERROR: NULL list node\n");
      return (NULL);
    }
  read = root;
  while (read)
    {
      if (read->index == index)
	return (read->data);
      read = read->next;
    }
  return (0);
}

Uint16		my_list_size(t_singlelist *root)
{
  t_singlelist	*read;
  Uint16	count;

  if (!root)
    {
      printf("FATAL ERROR: NULL list node\n");
      return (0);
    }
  read = root;
  count = 0;
  while (read)
    {
      read = read->next;
      ++count;
    }
  return (count);
}

void		list_clear(t_singlelist **root)
{
  t_singlelist	*read;
  t_singlelist	*next;

  if (!root)
    {
      printf("FATAL ERROR: NULL list node\n");
      return ;
    }
  read = *root;
  while (read)
    {
      next = read->next;
      mem_free(read);
      read = next;
    }
  *root = NULL;
}

