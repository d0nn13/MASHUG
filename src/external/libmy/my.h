/*
** my.h for libmy in /Users/ahamad_s/informatique/ETNA/Piscine/TCM-PIS1/Jour_05/libmy
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sat Oct 26 16:51:11 2013 AHAMADA Samir
** Last update Sun Apr 20 23:23:03 2014 AHAMADA Samir
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>

void    my_putchar(char c);
int     my_isneg(int n);
int     my_put_nbr(int nb);
int	my_put_unbr(unsigned int nb);
int	my_putnbr_base(int nb, char *base);
int	my_putunbr_base(unsigned int nb, char *base);
int     my_swap(int *a, int *b);
int     my_putstr(char *str);
int     my_strlen(char *str);
int     my_getnbr(char *str);
void    my_sort_int_tab(int *tab, int size);
int     my_power_rec(int nb, int power);
int     my_square_root(int nb);
int     my_is_prime(int nombre);
int     my_find_prime_sup(int nb);
char    *my_strcpy(char *dest, char *src);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_revstr(char *str);
char    *my_strstr(char *str, char *to_find);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strupcase(char *str);
char    *my_strlowcase(char *str);
char    *my_strcapitalize(char *str);
int     my_str_isalpha(char *str);
int     my_str_isnum(char *str);
int     my_str_islower(char *str);
int     my_str_isupper(char *str);
int     my_str_isprintable(char *str);
int     my_showstr(char *str);
char    *my_strcat(char *str1, char *str2);
char    *my_strncat(char *str1, char *str2, int n);
int     my_strlcat(char *str1, char *str2, int n);
/* int	my_printf(char *fmt, ...); COMING SOON */

/* List handling functions */
typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

t_list	*my_params_in_list(int ac, char **av);
int	my_list_size(t_list *begin);
int	my_rev_list(t_list **begin);
int	my_apply_on_list(t_list *begin, int (*f)());
int	my_apply_on_eq_in_list(t_list *begin, int (*f)(),
			       void *data_ref, int (*cmp)());
void	*my_find_elm_eq_in_list(t_list *begin, void *data_ref,
				int (*cmp)());
t_list	*my_find_node_eq_in_list(t_list *begin, void *data_ref,
				 int (*cmp)());
int	my_rm_all_eq_from_list(t_list **begin, void *data_ref,
			       int (*cmp)());
int	my_add_list_to_list(t_list **begin1,t_list *begin2);
int	my_sort_list(t_list **begin,int (*cmp)());
int	my_put_elem_in_sort_list(t_list **begin, void *data,
				 int (*cmp)());
int	my_add_sort_list_to_sort_list(t_list **begin1, t_list *begin2,
				      int (*cmp)());

/* --------------- Extra functions --------------- */

/* Memory allocation */
typedef enum	e_mem_error
  {
    E_MALLOC,
    E_MMLEAK
  }		mem_error;

void	*mem_alloc(size_t size);
void	mem_free(void *ptr);
void	mem_leakchk();
int	mem_count();
int	mem_strerror(mem_error r);

/* Extra list handling functions */
t_list	*list_make_node();
void	list_push(void *data, t_list **node);
void	list_clear(t_list **head);


#endif /* !MY_H */
