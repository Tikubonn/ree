#include <ree.h>

static ree_size __len (char *sequence){
  ree_size count = 0;
  while (*sequence++) count++;
  return count;
}

ree_string* __stdcall make_ree_string0 (char *sequence){
  ree_size size = __len(sequence);
  return make_ree_string(sequence, size);
}
