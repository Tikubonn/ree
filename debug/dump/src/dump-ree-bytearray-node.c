#include <ree.h>
#include <stdio.h>

int dump_ree_bytearray_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
	int status1 = dump_ree_bytearray_node_without_next(stream, node, ree, indentation);
	if (status1)
		return 1;
	
	return dump_ree_node(stream, node->next, ree, indentation);
	
}
