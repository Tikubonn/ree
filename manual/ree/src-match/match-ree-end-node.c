#include <ree.h>

int match_ree_end_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  if (ree_stream_eof(stream)){
    return match_ree_node(stream, node->next, ree, found);
  }
  
  else {
    *found = false;
    return 0;
  }
  
}
