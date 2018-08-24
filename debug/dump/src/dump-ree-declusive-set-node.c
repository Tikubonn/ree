#include <ree.h>
#include <stdio.h>

static int __dump (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
	switch (node->type){
		case REE_BYTE_NODE: return dump_ree_byte_node_without_next(stream, node, ree, indentation);
		case REE_BYTEARRAY_NODE: return dump_ree_bytearray_node_without_next(stream, node, ree, indentation);
		case REE_RANGE_NODE: return dump_ree_range_node_without_next(stream, node, ree, indentation);
		default: return 1;
	}
}

int dump_ree_declusive_set_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "declusive set\n");
  
  ree_node *nd = node->set_node.set_node;
  while (nd != NULL){
    
    int status1 = __dump(stream, nd, ree, indentation + 2);
    if (status1)
      return 1;
    
    nd = next_ree_node(nd);
    
  }
  
	return dump_ree_node(stream, node->next, ree, indentation);
  
}
