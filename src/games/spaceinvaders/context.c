/*
** spacecontext.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/devc/spaceinvaders
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:34:38 2014 FOFANA Ibrahim
** Last update Fri Sep 26 03:02:14 2014 ENNEBATI Yassine
*/

#include "../../base/memory.h"
#include "context.h"

#define NB_SPACE_LIVES 3

static t_spacecontext *spacecontext = NULL;

Uint8 spacecontext_init()
{
  spacecontext = mem_alloc(1, sizeof(t_spacecontext));
  spacecontext->score = 0;
  spacecontext->lives = NB_SPACE_LIVES;
  spacecontext->wave = 0;
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
