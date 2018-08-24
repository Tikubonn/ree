#include <ree.h>
#include <stdio.h>

int dump_ree_repeat_necessary_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "repeat +%s\n", node->repeat_necessary_node.minimum ? " min" : "");
  
  int status2 = dump_ree_node(stream, node->repeat_necessary_node.repeat_node, ree, indentation + 2);
  if (status2)
    return 1;

	return dump_ree_node(stream, node->next, ree, indentation);
  
}
