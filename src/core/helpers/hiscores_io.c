/*
** hiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Wed Sep 24 17:45:34 2014 FOFANA Ibrahim
*/

#include "../../base/memory.h"
#include "../log.h"
#include "../handlers.h"
#include "../helpers.h"

#include "../../base/list.h"

#include "hiscores_io.h"


static Uint8	sort_entries(t_hiscores *hiscores);
static Uint8	insert_entry(t_hiscores *hiscores, t_hiscoreholder entry);
static char	*game_name[] = {
  "spaceinvaders",
  "galaga",
  "rtype"
};

Uint8	load_hiscores(t_hiscores *hiscores, char *current_game)
{
  xml_hiscore_set_game_filter(current_game);
  hiscores->count = xml_parse("media/hiscores.xml", HISCORES_XML, NULL);
  if (!hiscores->count)
    return (0);
  hiscores->entries = mem_alloc(hiscores->count, sizeof(t_hiscoreholder));
  xml_parse("media/hiscores.xml", HISCORES_XML, hiscores->entries);
  sort_entries(hiscores);

  return (1);
}

Uint8	save_hiscores(t_hiscoreholder entry, char *current_game)
{
  t_singlelist	*all_hiscores;
  t_hiscores	hiscores;
  Uint8		i;

  all_hiscores = list_make_node();
  for (i = 0; game_name[i]; i++)
  {
    load_hiscores(&hiscores, game_name[i]);
    if (!strcmp(game_name[i], current_game))
      insert_entry(&hiscores, entry);
    list_push(&hiscores, &all_hiscores);
  }
/* TODO: call hiscores_rewrite(all_hiscore)*/
  while ((all_hiscores = all_hiscores->next))
    free_hiscores((t_hiscores *)all_hiscores->data);
  list_clear(&all_hiscores);
  return (1);
}

void	free_hiscores(t_hiscores *hiscores)
{
  Uint8	i;

  for (i = 0; i < hiscores->count; ++i)
    mem_free(hiscores->entries[i].nickname);
  mem_free(hiscores->entries);
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

static Uint8	insert_entry(t_hiscores *hiscores, t_hiscoreholder entry)
{
  Uint8	i;
  Uint8	rank_entry;

  for (i = 0; i < hiscores->count; i++)
    if (hiscores->entries[i].score < entry.score)
      break;
  rank_entry = i;
  for (i = hiscores->count - 2; i >= 0 && i > rank_entry; i--)
  {
   hiscores->entries[i].nickname = hiscores->entries[i - 1].nickname;
    hiscores->entries[i].score = hiscores->entries[i - 1].score;
  }
  hiscores->entries[rank_entry].nickname = entry.nickname;
  hiscores->entries[rank_entry].score = entry.score;

  return (1);
}
