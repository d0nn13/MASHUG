/*
** sfx.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders/src
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Sun Apr 20 21:59:36 2014 AHAMADA Samir
** Last update Wed Apr 30 01:34:54 2014 AHAMADA Samir
*/

#ifndef SFX_H
#define SFX_H

typedef struct	s_wav
{
  Uint8		*buf;
  Uint32	len;
}		t_wav;

typedef enum
  {
    BLIP_SFX,
    LAST_SFX
  }		t_sound;

void	load_sounds();

void	free_sounds();

#endif /* !SFX_H */
