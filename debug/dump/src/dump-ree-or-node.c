#include <ree.h>
#include <stdio.h>

int dump_ree_or_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "or\n");
  
  int status2 = dump_ree_node(stream, node->or_node.or_node1, ree, indentation + 2);
  if (status2)
    return 1;

  int status3 = dump_ree_indentation(stream, indentation);
  if (status3)
    return 1;
  
  fprintf(stream, "or else\n");
  
  int status4 = dump_ree_node(stream, node->or_node.or_node2, ree, indentation + 2);
  if (status4)
    return 1;

  return dump_ree_node(stream, node->next, ree, indentation);
  
}
