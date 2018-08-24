#include <ree.h>

int match_ree_group_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  ree_size beginning = ree_stream_index(stream);
  
  bool fnd;
  int status1 = match_ree_node(stream, node->group_node.group_node, ree, &fnd);
  if (status1)
    return 1;
  
  if (fnd){
    
    node->group_node.match_temp_beginning = beginning;
    node->group_node.match_temp_end = ree_stream_index(stream);
    return match_ree_node(stream, node->next, ree, found);
    
  }
  
  else {
    *found = false;
    return 0;
  }
  
}
