/*
** singlelist.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu Jun 26 01:46:35 2014 AHAMADA Samir
** Last update Thu Jun 26 08:19:51 2014 AHAMADA Samir
*/

/*
**
**
*/

#include "memory.h"

#include "list.h"

t_singlelist	*list_make_node()
{
  t_singlelist	*node;

  node = mem_alloc(sizeof(t_list));
  node->data = NULL;
  node->next = NULL;
  node->index = 0;
  return (node);
}

void		list_push(void *data, t_singlelist **node)
{
  (*node)->next = list_make_node();
  *node = (*node)->next;
  (*node)->data = data;
  (*node)->index = my_list_size(*node);
}

void		list_clear(t_singlelist **head)
{
  t_singlelist	*read;
  t_singlelist	*next;

  read = *head;
  while (read)
    {
      next = read->next;
      mem_free(read);
      read = next;
    }
  *head = NULL;
}
