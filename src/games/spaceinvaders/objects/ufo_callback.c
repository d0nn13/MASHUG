/*
** ufo_callback.c for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug/src/games/spaceinvaders/objects
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Sun Sep  7 15:14:45 2014 FOFANA Ibrahim
** Last update Sun Sep  7 15:49:40 2014 FOFANA Ibrahim
*/

#include "ufo_callback.h"
#include "../../../core/handlers.h"

void	spaceufo_display(t_spaceufo *ufo)
{
    draw_sprite(ufo->sprite, &ufo->rect);
}

void	spaceufo_move()
{
}

void	spaceufo_collide()
{
}
