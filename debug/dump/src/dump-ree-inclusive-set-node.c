#include <ree.h>
#include <stdio.h>

int dump_ree_inclusive_set_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "inclusive set\n");
  
  ree_node *nd = node->set_node.set_node;
  while (nd != NULL){
    
    int status1 = dump_ree_node(stream, nd, ree, indentation + 2);
    if (status1)
      return 1;
    
    nd = next_ree_node(nd);
    
  }
  
  return 0;
  
}
