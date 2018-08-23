#include <ree.h>

int compile_ree_byte (ree_stream *stream, ree_builder *builder){
  
  int character = peek_ree_stream(stream);
  if (character == REE_STREAM_EOF)
    return REE_SYNTAX_ERROR;
  
  else if (character == '\\'){
    int status1 = seek_ree_stream(1, stream);
    if (status1)
      return status1;
  }
  
  ree_size index = ree_stream_index(stream);
  
  int status1 = seek_ree_stream(1, stream);
  if (status1)
    return status1;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
	if (node == NULL)
		return REE_NOT_ENOUGH_MEMORY;
	
  node->type = REE_BYTE_NODE;
  node->byte_node.index = index;

  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return status10;
  return 0;
  
}
