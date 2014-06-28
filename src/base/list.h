/*
** list.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Jun 25 19:03:19 2014 AHAMADA Samir
** Last update Sat Jun 28 17:06:17 2014 AHAMADA Samir
*/

/*
**	@file	base/list.h
**	@brief	Linked lists
*/

typedef struct		s_singlelist
{
  void			*data;
  struct s_singlelist	*next;
  Sint16		index;
}			t_singlelist;

t_singlelist	*list_make_node();
void		list_push(void *data, t_singlelist **node);
void		*list_get(t_singlelist *head, Uint16 index);
Uint16		my_list_size(t_singlelist *begin);
void		list_clear(t_singlelist **head);
