/*
** audio.c for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 27 12:10:05 2014 AHAMADA Samir
** Last update Sun Apr 27 12:30:12 2014 AHAMADA Samir
*/

#include <SDL2/SDL.h>
#include "log.h"
#include "audio.h"



Uint32	audio_init()
{
  if (SDL_InitSubSystem(SDL_INIT_AUDIO))
    {
      SDL_LogError(AUD_LCAT, "Couldn't initialize video : %s", SDL_GetError());
      return (-1);
    }
  return (0);
}

void	audio_destroy()
{
  SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
