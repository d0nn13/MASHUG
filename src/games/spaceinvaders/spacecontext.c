/*
** context.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/devc/spaceinvaders
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:34:38 2014 FOFANA Ibrahim
** Last update Fri Sep  5 15:11:23 2014 FOFANA Ibrahim
*/

#include "spacecontext.h"

#define NB_SPACE_LIVES 3

static t_spacecontext *spacecontext = NULL;

void spacecontext_init()
{
  space_context = mem_alloc(1, sizeof(t_spacecontext));
  space_context->lives = NB_SPACE_LIVES;
  space_context->score = 0;
}

void spacecontext_destroy()
{
  men_free(space_context);
  space_context = NULL;
}

t_spacecontext *get_spacecontext()
{
  return (space_context);
}
