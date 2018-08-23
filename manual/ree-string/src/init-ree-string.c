#include <ree.h>

void __stdcall init_ree_string (char *sequence, ree_size size, ree_string *string){
  string->sequence = sequence;
  string->size = size;
}
