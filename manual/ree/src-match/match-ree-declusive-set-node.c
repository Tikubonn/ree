#include <ree.h>

static int __match (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  switch (node->type){
    case REE_BYTE_NODE:
      return match_ree_byte_node_without_next(stream, node, ree, found);
    case REE_BYTEARRAY_NODE:
      return match_ree_bytearray_node_without_next(stream, node, ree, found);
    case REE_RANGE_NODE:
      return match_ree_range_node_without_next(stream, node, ree, found);
    default:
      return 1;
  }
}

int match_ree_declusive_set_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  ree_stream sm = *stream;
  
  ree_node *nd = node->set_node.set_node;
  while (nd != NULL){
    
    *stream = sm;
    
    bool fnd;
    int status1 = __match(stream, nd, ree, &fnd);
    if (status1)
      return 1;
    
    if (fnd){
      *found = false;
      return 0;
    }
    
    nd = next_ree_node(nd);
    
  }
  
  return match_ree_node(stream, node->next, ree, found);
  
}
