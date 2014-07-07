/*
** list.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Wed Jun 25 19:03:19 2014 AHAMADA Samir
** Last update Fri Jul  4 20:46:36 2014 AHAMADA Samir
*/

/**
 *	@file	base/list.h
 *	@brief	Linked lists
 */

typedef struct		s_singlelist
{
  void			*data;
  struct s_singlelist	*next;
  Sint16		index;
}			t_singlelist;

/**
 *	@brief	Creates an heap-allocated empty new node with index set to 0
 */
t_singlelist	*list_make_node();

/**
 *	@brief	Pushes data to the end of a singly-linked list
 *
 *	Appends data to the tail of a single-linked list and makes the node
 *	ready for another push
 *
 *	@param	data A pointer to the data to store
 *	@param	tail The address of the pointer to the last node of a singly-linked list
 */
void		list_push(void *data, t_singlelist **tail);

/**
 *	@brief	Get a pointer to a specific node in a singly-linked list
 *
 *	@param	root The root of a singly-linked list
 *	@param	index The index of the wanted node in the singly-linked list
 *
 *	@return	A pointer to the data at in the specified node
 */
void		*list_get(t_singlelist *root, Uint16 index);

/**
 *	@brief	Get a signly-linked list size value
 *
 *	@param	root The root of a singly-linked list
 *	@return	The size of a singly-linked list as an integer
 */
Uint16		my_list_size(t_singlelist *root);

/**
 *	@brief	Destroys all nodes in a singly-linked list
 *
 *	This function does NOT destroy the data stored in the nodes of the list
 *
 *	@param	root The root of a singly-linked list
 */
void		list_clear(t_singlelist **root);
