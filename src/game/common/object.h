/*
** object.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Jun 15 00:37:16 2014 AHAMADA Samir
** Last update Sun Jun 15 00:57:34 2014 AHAMADA Samir
*/

#ifndef GAME_COMMON_OBJECT_H
#define GAME_COMMON_OBJECT_H

/**
 * Object types enum
 */
typedef enum    e_object_type
{
  SHIP_OBJ = 1,
  ALIEN_OBJ,
  S_MISSILE_OBJ,
  A_MISSILE_OBJ
}               t_object_type;

/**
 * Object structure def
 */
typedef struct	s_object
{
  SDL_Point	pos;
  SDL_Texture	*spr;
  Uint8		life;
  t_object_type type;
}		t_object;

/**
 * Object linked list container def
 */
typedef struct          s_object_list
{
  t_object              *obj;
  struct s_object_list  *next;
}                       t_object_list

/**
 * Allocates (counted) memory for a new object
 */
t_object  *make_object(t_object_type t);

/**
 * Pushes new object in container
 */
void      push_object(t_object *o);

/**
 * Destroys an object's allocated memory
 */
void      destroy_object(t_object *o);

/**
 * Gets number of allocated objects
 */
Uint16    get_object_count(t_object_type t);

#endif /* !GAME_COMMON_OBJECT_H */
