/*
** common.c for  in /Users/Yassine/Code/ETNA/projet/c/mashug/src
** 
** Made by ENNEBATI Yassine
** Login   <enneba_y@etna-alternance.net>
** 
** Started on  Fri Jul 25 16:42:25 2014 ENNEBATI Yassine
** Last update Sat Jul 26 17:44:50 2014 ENNEBATI Yassine
*/

#include "fonts.h"
#include "sfx.h"

#include "common.h"

Sint32	common_init()
{
  load_common_fonts();
  load_common_sfx();
  return (0);
}

void	common_destroy()
{
  free_common_fonts();
  free_common_sfx();
}
