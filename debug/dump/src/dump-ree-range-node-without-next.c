#include <ree.h>
#include <stdio.h>

static int __dump (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  switch (node->type){
    case REE_BYTE_NODE: return dump_ree_byte_node_without_next(stream, node, ree, indentation);
    case REE_BYTEARRAY_NODE: return dump_ree_bytearray_node_without_next(stream, node, ree, indentation);
    default: return 1;
  }
}

int dump_ree_range_node_without_next (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "range\n");
  
  int status2 = 
    __dump(stream, node->range_node.range_node1, ree, indentation + 2) || 
    __dump(stream, node->range_node.range_node2, ree, indentation + 2);
  if (status2)
    return 1;

  return 0;
  
}
