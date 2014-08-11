/*
** alien.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:10:42 2014 ENNEBATI Yassine
** Last update Sun Aug 10 02:24:01 2014 ENNEBATI Yassine
*/

#include "../../../base/memory.h"
#include "../../../core/handlers.h"
#include "../../../core/helpers.h"
#include "../spacespritesheet.h"
#include "alien_callback.h"

#include "alien.h"

#define NB_ALIENS	55

static t_singlelist	*aliens;

static void	sprite_select(Uint8 index, t_spriteholder const **sh)
{
  if (index < 11)
  {
    sh[0] = get_sprite(get_space_spritesheet(), "alien0a");
    sh[1] = get_sprite(get_space_spritesheet(), "alien0b");
  }
  else if (index < 33)
  {
    sh[0] = get_sprite(get_space_spritesheet(), "alien1a");
    sh[1] = get_sprite(get_space_spritesheet(), "alien1b");
  } 
  else if (index < 55)
  {
    sh[0] = get_sprite(get_space_spritesheet(), "alien2a");
    sh[1] = get_sprite(get_space_spritesheet(), "alien2b");
  }
}

void			space_init_alien()
{
  t_spacealien		*alien;
  t_singlelist		*node;
  Uint8			i;

  aliens = list_make_node();
  node = aliens;
  for (i = 0; i < NB_ALIENS; ++i)
  {
    alien = mem_alloc(sizeof(t_spacealien));
    alien->display = &spacealien_display;
    alien->move = &spacealien_move;
    alien->fire = &spacealien_fire;
    alien->collide = &spacealien_collide;
    sprite_select(i, alien->sprite);
    alien->rect = rect_factory(350, 520, alien->sprite[0]->rect.w * 2,
			       alien->sprite[0]->rect.h * 2);
    list_push(alien, &node);
  }
}

t_singlelist	*get_spacealiens()
{
  return (aliens);
}
