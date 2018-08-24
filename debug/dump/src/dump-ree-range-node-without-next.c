#include <ree.h>
#include <stdio.h>

int dump_ree_range_node_without_next (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "range\n");
  
  int status2 = 
    dump_ree_node(stream, node->range_node.range_node1, ree, indentation + 2) || 
    dump_ree_node(stream, node->range_node.range_node2, ree, indentation + 2);
  if (status2)
    return 1;

	return 0;
  
}
