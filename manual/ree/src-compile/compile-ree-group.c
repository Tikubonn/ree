#include <ree.h>

int compile_ree_group (ree_stream *stream, ree_builder *builder){
	
  int character = get_ree_stream(stream);
  if (character != '(')
    return REE_SYNTAX_ERROR;

  ree_node *rot = builder->root;
  ree_node *nod = builder->node;
  
  builder->root = NULL;
  builder->node = NULL;

  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  int status1 = connect_to_ree_builder_group_node(node, builder);
  if (status1)
    return status1;
  
  while (1){
    
    int character = peek_ree_stream(stream);
    if (character == REE_STREAM_EOF)
      return REE_SYNTAX_ERROR;

    if (character == ')'){
      int status1 = seek_ree_stream(1, stream);
      if (status1)
        return 1;
      break;
    }
    
    int status1 = compile_ree_automatically(stream, builder);
    if (status1)
      return 1;
    
  }
  
  node->type = REE_GROUP_NODE;
  node->group_node.group_node = builder->root;
  
  builder->root = rot;
  builder->node = nod;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;
  
}
