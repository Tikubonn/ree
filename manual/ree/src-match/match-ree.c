#include <ree.h>

int __stdcall match_ree (ree_string *source, ree *ree, bool *found){
  
  ree_stream stream;
  init_ree_stream_from_string(source, &stream);
  
  int status1 = match_ree_node(&stream, ree->root, ree, found);
  if (status1)
    return 1;
  return 0;
  
}
