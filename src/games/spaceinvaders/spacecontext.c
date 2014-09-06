/*
** spacecontext.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/devc/spaceinvaders
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:34:38 2014 FOFANA Ibrahim
** Last update Fri Sep  5 15:11:23 2014 FOFANA Ibrahim
*/

#include "../../base/memory.h"
#include "spacecontext.h"

#define NB_SPACE_LIVES 3

static t_spacecontext *spacecontext = NULL;

Uint8 spacecontext_init()
{
  spacecontext = mem_alloc(1, sizeof(t_spacecontext));
  spacecontext->lives = NB_SPACE_LIVES;
  spacecontext->score = 0;
  return (0);
}

void spacecontext_destroy()
{
  mem_free(spacecontext);
  spacecontext = NULL;
}

t_spacecontext *get_spacecontext()
{
  return (spacecontext);
}
