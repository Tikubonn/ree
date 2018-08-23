#include <ree.h>

int compile_ree_or (ree_stream *stream, ree_builder *builder){
  
  int character = get_ree_stream(stream);
  if (character != '|')
    return REE_SYNTAX_ERROR;
  
  ree_node *nodea = builder->root;
  builder->root = NULL;
  builder->node = NULL;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  while (1){
    
    int character = peek_ree_stream(stream);
    if (character == REE_STREAM_EOF || 
        character == ')' || 
        character == '|')
      break;
    
    int status1 = compile_ree_automatically(stream, builder);
    if (status1)
      return status1;
    
  }

  ree_node *nodeb = builder->root;
  builder->root = NULL;
  builder->node = NULL;
  
  node->type = REE_OR_NODE;
  node->or_node.or_node1 = nodea;
  node->or_node.or_node2 = nodeb;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;

}
