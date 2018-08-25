#include <ree.h>

int match_ree_or_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  ree_stream sm = *stream;
  
  bool fnd1;
  int status1 = match_ree_node(stream, node->or_node.or_node1, ree, &fnd1);
  if (status1)
    return 1;
  
  if (fnd1 == true){
    return match_ree_node(stream, node->next, ree, found);
  }
  
  *stream = sm;
  
  bool fnd2;
  int status2 = match_ree_node(stream, node->or_node.or_node2, ree, &fnd2);
  if (status2)
    return 1;
  
  if (fnd2 == true){
    return match_ree_node(stream, node->next, ree, found);
  }
  
  else {
    *found = false;
    return 0;
  }
  
}
