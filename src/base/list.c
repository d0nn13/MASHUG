/*
** list.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jun 26 01:46:35 2014 AHAMADA Samir
** Last update Sat Jun 28 17:08:15 2014 AHAMADA Samir
*/

/*
**
**
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

void		list_push(void *data, t_singlelist **node)
{
  if (!node)
    {
      printf("FATAL ERROR: NULL list node\n");
      return ;
    }
  (*node)->next = list_make_node();
  (*node)->next->index = (*node)->index + 1;
  *node = (*node)->next;
  (*node)->data = data;
}

void		*list_get(t_singlelist *head, Uint16 index)
{
  t_singlelist	*read;

  if (!head)
    {
      printf("FATAL ERROR: NULL list node\n");
      return (NULL);
    }
  read = head;
  while (read)
    {
      if (read->index == index)
	return (read->data);
      read = read->next;
    }
  return (0);
}

Uint16		my_list_size(t_singlelist *begin)
{
  t_singlelist	*read;
  Uint16	count;

  if (!begin)
    {
      printf("FATAL ERROR: NULL list node\n");
      return (0);
    }
  read = begin;
  count = 0;
  while (read)
    {
      read = read->next;
      ++count;
    }
  return (count);
}

void		list_clear(t_singlelist **head)
{
  t_singlelist	*read;
  t_singlelist	*next;

  if (!head)
    {
      printf("FATAL ERROR: NULL list node\n");
      return ;
    }
  read = *head;
  while (read)
    {
      next = read->next;
      mem_free(read);
      read = next;
    }
  *head = NULL;
}

