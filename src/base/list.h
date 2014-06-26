/*
** list.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Jun 25 19:03:19 2014 AHAMADA Samir
** Last update Thu Jun 26 01:25:33 2014 AHAMADA Samir
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

typedef struct		s_doublelist
{
  void			*data;
  struct s_doublelist	*prev;
  struct s_doublelist	*next;
  Sint16		index;
}			t_doublelist
