#include <ree.h>
#include <stdio.h>

int dump_ree_any_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "any\n");
  
  return dump_ree_node(stream, node->next, ree, indentation);

}
