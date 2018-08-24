#include <ree.h>

int match_ree_bytearray_node_without_next (ree_stream *stream, ree_node *node, ree *ree, bool *found){

  ree_size index = node->bytearray_node.index_beginning;
  ree_size size = node->bytearray_node.index_end;
  
  while (index < size){
    
    int charactera = get_ree_stream(stream);
    if (charactera == REE_STREAM_EOF){
      *found = false;
      return 0;
    }
    
    char characterb;
    int status1 = get_ree_string(index, ree->source, &characterb);
    if (status1)
      return 1;
    
    if (charactera != characterb){
      *found = false;
      return 0;
    }
    
    index++;
  
  }
  
  *found = true;
  return 0;
  
}
