#include <ree.h>
#include <stdio.h>

int dump_ree_byte_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "byte '");
  
  char character;
  int status2 = get_ree_string(node->byte_node.index, ree->source, &character);
  if (status2)
    return 1;
  
  dump_ree_character(character, stream);
  
  fprintf(stream, "'\n");
  
  return 0;
  
}
