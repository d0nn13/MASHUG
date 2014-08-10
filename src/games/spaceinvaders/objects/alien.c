/*
** alien.c for MASHUG in /Users/Yassine/Code/ETNA/projet/c/mashug/src/games/spaceinvaders/objects/alien
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Sun Aug 10 01:10:42 2014 ENNEBATI Yassine
** Last update Sun Aug 10 02:24:01 2014 ENNEBATI Yassine
*/

#include "../../../../core/handlers.h"
#include "../../../../core/helpers.h"
#include "../../spacespritesheet.h"
#include "alien_callback.h"

#include "alien.h"

static t_spacealien	aliens;

void			space_init_alien(char const *sprite)
{
  t_spriteholder	*sprite;

  if (!ptr_chk(sprite, "sprite", APP_LCAT, "space_init_alien"))
    return ;
  sprite = get_sprite(get_space_spritesheet(), sprite);
  alien.display = &spacealien_display;
  alien.move = &spacealien_move;
  alien.fire = NULL;
  alien.collide = NULL;
  alien.sprite = sprite;
  alien.rect = rect_factory(350, 520, sprite->rect.w * 2, sprite->rect.h * 2);
}

t_spacealien	*get_spacealien()
{
  return (&alien);
}  


