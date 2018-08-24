#include <ree.h>

int __stdcall copy_ree_string_manually (ree_string *stringa, ree_string *stringb){
  
  ree_size sizea = ree_string_length(stringa);
  ree_size sizeb = ree_string_length(stringb);

  if (sizeb < sizea)
    return REE_NOT_ENOUGH_MEMORY;
  
  if (sizeb != sizea)
    return REE_ERROR;
  
  ree_size index;
  for (index = 0; index < sizea; index++){
    stringb->sequence[index] = stringa->sequence[index];
  }
  
  return 0;
  
}
