/*
** xml_hiscore_writer_handler.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Wed Sep 24 14:49:09 2014 FOFANA Ibrahim
** Last update Thu Sep 25 20:20:42 2014 FOFANA Ibrahim
*/

/**
 *	@file	xml_hiscore_writer_handler.c
 *	@brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "../../base/memory.h"
#include "../../base/list.h"
#include "../log.h"
#include "../handlers.h"

#define DTD	"dtd/hiscores.dtd"
#define CAST(n)	((xmlChar *)n)

static void	insert_body_game(xmlNodePtr root_node, t_hiscores *hiscores, Uint8 nb_games);

Uint8	hiscores_rewrite(t_hiscores *hiscores, Uint8 nb_games)
{
  xmlDocPtr	doc;
  xmlNodePtr	root_node;

  doc = xmlNewDoc(CAST("1.0"));
  root_node = xmlNewNode(NULL, CAST("hiscores"));
  xmlDocSetRootElement(doc, root_node);
  xmlCreateIntSubset(doc, CAST("hiscores"), NULL, CAST(DTD));
  insert_body_game(root_node, hiscores, nb_games);
  xmlSaveFormatFileEnc("media/hiscores.xml", doc, "UTF-8", 1);
  xmlFreeDoc(doc);
  xmlCleanupParser();
  return (1);
}

static void	insert_body_game(xmlNodePtr root_node, t_hiscores *h, Uint8 nb_games)
{
  int		i;
  int		j;
  char		buff[20];
  xmlNodePtr	node_game;
  xmlNodePtr	node_entry;

  for (i = 0; i < nb_games; i++)
  {
    node_game = xmlNewChild(root_node, NULL, CAST("game"), NULL);
    xmlNewProp(node_game, CAST("name"), CAST(h[i].game_name));
    for (j = 0; j < h[i].count; j++)
    {
      node_entry = xmlNewChild(node_game, NULL, CAST("entry"), NULL);
      xmlNewProp(node_entry, CAST("nickname"), CAST(h[i].entries[j].nickname));
      sprintf(buff, "%d", h[i].entries[j].score);
      xmlNewProp(node_entry, CAST("score"), CAST(buff));
    }
  }
}
