#include <ree.h>

int get_ree_string (ree_size index, ree_string *string, char *character){
  if (string->size <= index)
    return REE_ERROR;
  *character = string->sequence[index];
  return 0;
}
