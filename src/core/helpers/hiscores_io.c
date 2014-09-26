/*
** hiscores_io.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Wed Sep 24 19:39:39 2014 FOFANA Ibrahim
** Last update Fri Sep 26 03:04:44 2014 FOFANA Ibrahim
*/

#include <string.h>
#include "../../base/memory.h"
#include "../log.h"
#include "../handlers.h"
#include "../helpers.h"
#include "../../base/list.h"

#include "hiscores_io.h"

#define NB_GAME 3

static Uint8	sort_entries(t_hiscores *hiscores);
static Uint8	insert_entry(t_hiscores *hiscores, t_hiscoreholder *entry);

Uint8	load_hiscores(t_hiscores *hiscores, char *current_game)
{
  xml_hiscore_set_game_filter(current_game);
  hiscores->count = xml_parse("media/hiscores.xml", HISCORES_XML, NULL);
  if (!hiscores->count)
    return (0);
  hiscores->entries = mem_alloc(hiscores->count, sizeof(t_hiscoreholder));
  hiscores->game_name = mem_alloc(1, (strlen(current_game) + 1));
  strcpy(hiscores->game_name, current_game);
  xml_parse("media/hiscores.xml", HISCORES_XML, hiscores->entries);
  sort_entries(hiscores);
  return (1);
}

Uint8	save_hiscores(t_hiscoreholder *entry, char *current_game)
{
  t_hiscores		*all_hiscores;
  Uint8			i;
  static const char	*game_name[NB_GAME] = {
    "spaceinvaders",
    "galaga",
    "rtype"
  };

  all_hiscores = mem_alloc(NB_GAME, sizeof(t_hiscores));
  for (i = 0; i < NB_GAME; i++)
  {
    load_hiscores(&all_hiscores[i], (char *)game_name[i]);
    if (!strcmp(game_name[i], current_game))
      insert_entry(&all_hiscores[i], entry);
  }
  hiscores_rewrite(all_hiscores, NB_GAME);
  for (i = 0; i < NB_GAME; i++)
    free_hiscores(&all_hiscores[i]);
  mem_free(all_hiscores);
  return (1);
}

void	free_hiscores(t_hiscores *hiscores)
{
  Uint8	i;

  for (i = 0; i < hiscores->count; ++i)
    mem_free(hiscores->entries[i].nickname);
  mem_free(hiscores->entries);
  mem_free(hiscores->game_name);
}

static Uint8	sort_entries(t_hiscores *hiscores)
{
  Uint8			i;
  Uint8			j;
  t_hiscoreholder	tmp;

  for (i = 0; i < hiscores->count; i++)
    for (j = i + 1; j < hiscores->count; j++)
    {
      if (hiscores->entries[i].score < hiscores->entries[j].score)
      {
	tmp.score = hiscores->entries[i].score;
	tmp.nickname = hiscores->entries[i].nickname;
	hiscores->entries[i].score = hiscores->entries[j].score;
	hiscores->entries[i].nickname = hiscores->entries[j].nickname;
	hiscores->entries[j].score = tmp.score;
	hiscores->entries[j].nickname = tmp.nickname;
      }
    }
  return (1);
}

static Uint8	insert_entry(t_hiscores *hiscores, t_hiscoreholder *entry)
{
  Uint8	i;
  Uint8	rank_entry;

  for (i = 0; i < hiscores->count; i++)
    if (hiscores->entries[i].score < entry->score)
      break;
  rank_entry = i;
  for (i = hiscores->count - 2; i > rank_entry; i--)
  {
    hiscores->entries[i].nickname = strdup(hiscores->entries[i - 1].nickname);
    hiscores->entries[i].score = hiscores->entries[i - 1].score;
  }
  hiscores->entries[rank_entry].nickname = strdup(entry->nickname);
  hiscores->entries[rank_entry].score = entry->score;
  return (1);
}
