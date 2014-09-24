/*
** hiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Wed Sep 24 10:54:51 2014 FOFANA Ibrahim
*/

#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"

#include "hiscores.h"

static Uint8	sort_entries(t_hiscores hiscores);
static Uint8	insert_entry(t_hiscores hiscores, t_hiscoreholder entry);

Uint8	load_hiscores(t_hiscores *hiscores)
{
  xml_hiscore_set_game_filter("spaceinvaders");
  hiscores->count = xml_parse("media/hiscores.xml", HISCORES_XML, NULL);
  if (!hiscores->count)
    return (0);
  hiscores->entries = mem_alloc(hiscores->count, sizeof(t_hiscoreholder));
  xml_parse("media/hiscores.xml", HISCORES_XML, hiscores->entries);
  sort_entries(*hiscores);

  return (1);
}

Uint8	save_spacehiscores(t_hiscoreholder entry)
{
  t_hiscores	hiscores;

  load_hiscores(&hiscores);
  insert_entry(hiscores, entry);

  return (1);
}

static Uint8	sort_entries(t_hiscores hiscores)
{
  Uint8			i;
  Uint8			j;
  t_hiscoreholder	tmp;

  for (i = 0; i < hiscores.count; i++)
    for (j = i + 1; j < hiscores.count; j++)
    {
      if (hiscores.entries[i].score < hiscores.entries[j].score)
      {
	tmp.score = hiscores.entries[i].score;
	tmp.nickname = hiscores.entries[i].nickname;
	hiscores.entries[i].score = hiscores.entries[j].score;
	hiscores.entries[i].nickname = hiscores.entries[j].nickname;
	hiscores.entries[j].score = tmp.score;
	hiscores.entries[j].nickname = tmp.nickname;
      }
    }

  return (1);
}

static Uint8	insert_entry(t_hiscores hiscores, t_hiscoreholder entry)
{
  Uint8	i;
  Uint8	rank_entry;

  for (i = 0; i < hiscores.count; i++)
    if (hiscores.entries[i].score < entry.score)
      break;
  rank_entry = i;
  for (i = hiscores.count - 2; i >= 0 && i > rank_entry; i--)
  {
    hiscores.entries[i].nickname = hiscores.entries[i - 1].nickname;
    hiscores.entries[i].score = hiscores.entries[i - 1].score;
  }
  hiscores.entries[rank_entry].nickname = entry.nickname;
  hiscores.entries[rank_entry].score = entry.score;

  return (1);
}
