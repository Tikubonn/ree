#include <ree.h>

ree_size __stdcall ree_string_length (ree_string *string){
  return string->size;
}
