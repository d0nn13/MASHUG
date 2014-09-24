/*
** hiscores.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders
**
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
**
** Started on  Mon Jul 14 16:28:26 2014 ENNEBATI Yassine
** Last update Wed Sep 24 08:56:31 2014 FOFANA Ibrahim
*/

#include <stdio.h>
#include "../../base/memory.h"
#include "../../core/log.h"
#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/handlers.h"
#include "../../core/helpers.h"
#include "../../core/launcher.h"
#include "../common/fonts.h"
#include "../common/sfx.h"
#include "spaceinvaders.h"
#include "sprites.h"
#include "core.h"
#include "menu.h"

#include "hiscores.h"


Uint8	load_hiscores(t_hiscores *hiscores)
{
  xml_hiscore_set_game_filter("spaceinvaders");
  hiscores->count = xml_parse("media/hiscores.xml", HISCORES_XML, NULL);
  if (!hiscores->count)
    return (0);
  hiscores->entries = mem_alloc(hiscores->count, sizeof(t_hiscoreholder));
  xml_parse("media/hiscores.xml", HISCORES_XML, hiscores->entries);
  return (1);
}

Uint8	save_spacehiscores();
