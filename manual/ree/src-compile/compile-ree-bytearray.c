#include <ree.h>

int compile_ree_bytearray (ree_stream *stream, ree_builder *builder){
  
  int character = get_ree_stream(stream);
  if (character != '<')
    return REE_SYNTAX_ERROR;
  
  ree_size beginning = ree_stream_index(stream);
  
  while (1){
    int character = get_ree_stream(stream);
    if (character == '>')
      break;
    if (character == REE_STREAM_EOF || 
        character == '^' || 
        character == '$' || 
        character == '.' || 
        character == '*' || 
        character == '+' || 
        character == '?' || 
        character == '<' || 
        character == '{' || 
        character == '}' || 
        character == '[' || 
        character == ']' || 
        character == '(' || 
        character == ')')
      return REE_SYNTAX_ERROR;
    if (character == '\\'){
      int status1 = seek_ree_stream(1, stream);
      if (status1)
        return status1;
    }
  }
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  node->type = REE_BYTEARRAY_NODE;
  node->bytearray_node.index_beginning = beginning;
  node->bytearray_node.index_end = ree_stream_index(stream);
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;

}
