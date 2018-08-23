#include <ree.h>

int compile_ree_beginning (ree_stream *stream, ree_builder *builder){
  
  int character = get_ree_stream(stream);
  if (character != '^')
    return REE_SYNTAX_ERROR;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  node->type = REE_BEGINNING_NODE;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return status10;
  return 0;
  
}
