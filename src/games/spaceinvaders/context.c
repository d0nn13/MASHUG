/*
** spacecontext.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/devc/spaceinvaders
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:34:38 2014 FOFANA Ibrahim
** Last update Fri Sep 26 03:33:49 2014 FOFANA Ibrahim
*/

#include "../../base/memory.h"
#include "context.h"

#define NB_SPACE_LIVES	3

static t_spacecontext	*spacecontext = NULL;

Uint8	spacecontext_init()
{
  spacecontext = mem_alloc(1, sizeof(t_spacecontext));
  spacecontext->score = 0;
  spacecontext->lives = NB_SPACE_LIVES;
  spacecontext->wave = 0;
  return (0);
}

void	spacecontext_destroy()
{
  mem_free(spacecontext);
  spacecontext = NULL;
}

t_spacecontext	*get_spacecontext()
{
  return (spacecontext);
}

void	spacecontext_increase_life_process()
{
  static Uint32 last_score = 0;

  if ((spacecontext->score - last_score) == 1500)
  {
    last_score = spacecontext->score;
    if (spacecontext->lives < 9)
      spacecontext->lives++;
  }
}
