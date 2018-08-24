#include <ree.h>
#include <stdio.h>

int dump_ree_bytearray_node (FILE *stream, ree_node *node, ree *ree, ree_size indentation){
  
  int status1 = dump_ree_indentation(stream, indentation);
  if (status1)
    return 1;
  
  fprintf(stream, "bytearray \"");
  
  ree_size index;
  for (index = node->bytearray_node.index_beginning; 
       index < node->bytearray_node.index_end; index++){
    
    char character;
    int status1 = get_ree_string(index, ree->source, &character);
    if (status1)
      return 1;
    
    dump_ree_character(character, stream);
    
  }
  
  fprintf(stream, "\"\n");
  
  return 0;

}
