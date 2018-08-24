#include <ree.h>

int match_ree_unnecessary_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  ree_stream sm = *stream;

  bool fnd;
  int status1 = match_ree_node(stream, node->unnecessary_node.unnecessary_node, ree, &fnd);
  if (status1)
    return 1;
  
  if (fnd == true){
    return match_ree_node(stream, node->next, ree, found);
  }
  
  else {
    *stream = sm;
    return match_ree_node(stream, node->next, ree, found);
  }
  
}
