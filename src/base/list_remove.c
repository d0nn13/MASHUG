/*
** list_remove.c for all in 
** 
** Made by Emmanuel Atse
** Login   <atse_e@etna-alternance.net>
** 
** Started on  Thu Sep 25 21:35:26 2014 Emmanuel Atse
** Last update Thu Sep 25 23:21:56 2014 Emmanuel Atse
*/

#include	"memory.h"

#include	"list.h"

static void	update_index(t_singlelist *node)
{
  for (; node; node = node->next)
    --node->index;
}

void		list_pop(t_singlelist *node, t_singlelist **root)
{
  t_singlelist	*prev_node;

  if (!root || !*root || !node)
  {
    fprintf(stderr, "FATAL ERROR: NULL list node\n");
    return ;
  }
  if (node == *root)
    {
      *root = node->next;
      update_index(*root);
      mem_free(node);
      return ;
    }
  else
    for (prev_node = *root; prev_node && prev_node->next != node;
	 prev_node = prev_node->next);
  if (!prev_node)
    {
      fprintf(stderr, "FATAL ERROR: Couldn't find the list's node\n");
      return ;
    }
  prev_node->next = node->next;
  update_index(node->next);
  mem_free(node);
}
