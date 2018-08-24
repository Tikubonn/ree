#include <ree.h>

int match_ree_beginning_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  ree_size index = ree_stream_index(stream);
  if (index == 0){
    return match_ree_node(stream, node->next, ree, found);
  }
  
  else {
    *found = false;
    return 0;
  }
  
}
