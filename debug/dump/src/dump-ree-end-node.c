#include <ree.h>
#include <stdio.h>

int dump_ree_end_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  fprintf(stream, "end\n");
  return 0;
}
