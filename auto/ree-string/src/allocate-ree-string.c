#include <ree.h>
#include <stdlib.h>

extern ree_string* __stdcall allocate_ree_string (ree_size size){
  
  ree_string *string = malloc(sizeof(ree_string));
  if (string == NULL)
    return NULL;
  
  char *sequence = malloc(size);
  if (sequence == NULL){
    free(string);
    return NULL;
  }
  
  init_ree_string(sequence, size, string);
  return string;
  
}
