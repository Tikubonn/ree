#include <ree.h>

int compile_ree_any (ree_stream *stream, ree_builder *builder){
  
  int character = get_ree_stream(stream);
  if (character != '.')
    return REE_SYNTAX_ERROR;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  node->type = REE_ANY_NODE;
  
  int status1 = connect_to_ree_builder_node(node, builder);
  if (status1)
    return status1;
  return 0;
  
}
