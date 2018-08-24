#include <ree.h>

int match_ree_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  
  if (node == NULL){
    *found = true;
    return 0;
  }
  
  switch (node->type){
    
    case REE_BEGINNING_NODE:
      return match_ree_beginning_node(stream, node, ree, found);
    
    case REE_END_NODE:
      return match_ree_end_node(stream, node, ree, found);
    
    case REE_ANY_NODE:
      return match_ree_any_node(stream, node, ree, found);
    
    case REE_BYTE_NODE:
      return match_ree_byte_node(stream, node, ree, found);
    
    case REE_BYTEARRAY_NODE:
      return match_ree_bytearray_node(stream, node, ree, found);
    
    case REE_REPEAT_FOR_NODE:
      return match_ree_repeat_for_node(stream, node, ree, found);
    
    case REE_REPEAT_NECESSARY_NODE:
      return match_ree_repeat_necessary_node(stream, node, ree, found);
    
    case REE_REPEAT_UNNECESSARY_NODE:
      return match_ree_repeat_unnecessary_node(stream, node, ree, found);
    
    case REE_INCLUSIVE_SET_NODE:
      return match_ree_inclusive_set_node(stream, node, ree, found);
    
    case REE_DECLUSIVE_SET_NODE:
      return match_ree_declusive_set_node(stream, node, ree, found);
    
    case REE_GROUP_NODE:
      return match_ree_group_node(stream, node, ree, found);
    
    case REE_OR_NODE:
      return match_ree_or_node(stream, node, ree, found);
    
    case REE_UNNECESSARY_NODE:
      return match_ree_unnecessary_node(stream, node, ree, found);
    
    default:
      return 1;
  
  }
  
}
