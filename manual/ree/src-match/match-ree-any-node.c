#include <ree.h>

int match_ree_any_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){

  int status1 = seek_ree_stream(1, stream);
  if (status1)
    return 1;
  
  return match_ree_node(stream, node->next, ree, found);
  
}
