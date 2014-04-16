/*
** memory.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src/base
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Mar 26 01:09:22 2014 AHAMADA Samir
** Last update Wed Mar 26 01:09:23 2014 AHAMADA Samir
*/

#include "my.h"
#include "memory.h"

enum error
  {
    E_MALLOC,
    E_MMLEAK
  };

static int	g_mem_count;

void	*mem_alloc(size_t size)
{
  void	*try;

  try = malloc(size);
  if (try)
    ++g_mem_count;
  else
    exit(mem_error(E_MALLOC));
  return (try);
}

void	mem_free(void *ptr)
{
  if (ptr)
    {
      free(ptr);
      --g_mem_count;
    }
}

void	mem_leakchk()
{
#ifdef MEM_DEBUG
  my_putchar('\n'); my_put_nbr(g_mem_count); my_putchar('\n');
#endif
  if (mem_count() != 0)
    mem_error(E_MMLEAK);
}

int	mem_count()
{
  return (g_mem_count);
}

int	mem_error(int err)
{
  if (err == E_MALLOC)
    my_putstr("Heap memory allocation error, exiting.\n");
  else if (err == E_MMLEAK)
    my_putstr("\nMemory leak detected.\n");
  return (-1);
}
