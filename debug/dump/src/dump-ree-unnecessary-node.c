#include <ree.h>
#include <stdio.h>

int dump_ree_unnecessary_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "unnecessary\n");
  
  int status2 = dump_ree_node(stream, node->unnecessary_node.unnecessary_node, ree, indentation + 2);
  if (status2)
    return 1;

	return dump_ree_node(stream, node->next, ree, indentation);
  
}
