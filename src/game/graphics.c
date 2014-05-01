/*
** graphics.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Thu May  1 18:22:44 2014 AHAMADA Samir
** Last update Thu May  1 18:41:54 2014 AHAMADA Samir
*/

#include "graphics.h"

static SDL_Texture	*game_texture;

Sint32	graphics_init()
{
  SDL_CreateTexture(get_renderer(), SDL_PIXELFORMAT_RGBA8888,
		    SDL_TEXTUREACCESS_STREAMING, 176, 154);
  return (0);
}

SDL_Texture	*get_gtexture()
{
  return (game_texture);
}

void	graphics_destroy()
{
  SDL_DestroyTexture(game_texture);
}
