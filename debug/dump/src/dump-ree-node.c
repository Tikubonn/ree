#include <ree.h>

int dump_ree_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  if (node == NULL)
    return 0;
  
  switch (node->type){
    case REE_BEGINNING_NODE: return dump_ree_beginning_node(stream, node, ree, indentation);
    case REE_END_NODE: return dump_ree_end_node(stream, node, ree, indentation);
    case REE_ANY_NODE: return dump_ree_any_node(stream, node, ree, indentation);
    case REE_BYTE_NODE: return dump_ree_byte_node(stream, node, ree, indentation);
    case REE_BYTEARRAY_NODE: return dump_ree_bytearray_node(stream, node, ree, indentation);
    case REE_REPEAT_FOR_NODE: return dump_ree_repeat_for_node(stream, node, ree, indentation);
    case REE_REPEAT_NECESSARY_NODE: return dump_ree_repeat_necessary_node(stream, node, ree, indentation);
    case REE_REPEAT_UNNECESSARY_NODE: return dump_ree_repeat_unnecessary_node(stream, node, ree, indentation);
    case REE_RANGE_NODE: return dump_ree_range_node(stream, node, ree, indentation);
    case REE_INCLUSIVE_SET_NODE: return dump_ree_inclusive_set_node(stream, node, ree, indentation);
    case REE_DECLUSIVE_SET_NODE: return dump_ree_declusive_set_node(stream, node, ree, indentation);
    case REE_OR_NODE: return dump_ree_or_node(stream, node, ree, indentation);
    case REE_UNNECESSARY_NODE: return dump_ree_unnecessary_node(stream, node, ree, indentation);
    default: return 1;
  }
  
}
