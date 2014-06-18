
#include "object.h"

static Uint16 object_count = 0;

t_object  *make_object(t_object_type t)
{
  t_object *o;

  o = 0;
  if (!(o = malloc(sizeof(t_object))))
    return (0);
  o->type = t;
  object_count++;
}

void      destroy_object(t_object *o)
{
  if (!o)
    return ;
  if (o->spr)
    free(o->spr);
  free(o);
  object_count--;
}

Uint16    get_object_count()
{
  return (object_count);
}