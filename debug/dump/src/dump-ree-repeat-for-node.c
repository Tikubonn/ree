#include <ree.h>
#include <stdio.h>

int dump_ree_repeat_for_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(
		stream,
    "repeat %d ~ %d\n",
    node->repeat_for_node.repeat_min,
    node->repeat_for_node.repeat_max
  );
  
  int status2 = dump_ree_node(stream, node->repeat_for_node.repeat_node, ree, indentation + 2);
  if (status2)
    return 1;

  return 0;
  
}
