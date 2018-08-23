#include <ree.h>

int compile_ree_set (ree_stream *stream, ree_builder *builder){
  
  int character1 = get_ree_stream(stream);
  if (character1 == '[')
    return 1;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  ree_node *rot = builder->root;
  ree_node *nod = builder->node;
  
  builder->root = NULL;
  builder->node = NULL;
  
  int type = REE_INCLUSIVE_SET_NODE;
  int character2 = peek_ree_stream(stream);
  if (character2 == '^'){
    int status1 = seek_ree_stream(1, stream);
    if (status1)
      return 1;
    type = REE_DECLUSIVE_SET_NODE;
  }
  
  int character3 = peek_ree_stream(stream);
  if (character3 == '-'){
    int status1 = compile_ree_byte(stream, builder);
    if (status1)
      return 1;
  }
  
  while (1){
    
    int character = peek_ree_stream(stream);
    
    if (character == REE_STREAM_EOF || 
        character == '^' || 
        character == '$' || 
        character == '.' || 
        character == '*' || 
        character == '+' || 
        character == '?' || 
        character == '>' || 
        character == '{' || 
        character == '}' || 
        character == '[' || 
        character == ']' || 
        character == '(' || 
        character == ')')
      return REE_SYNTAX_ERROR;
    
    else if (character == ']'){
			int status = seek_ree_stream(1, stream);
			if (status)
				return 1;
			break;
		}
    
    else if (character == '-'){
      int status = compile_ree_range(stream, builder);
      if (status)
        return status;
    }
    
    else {
      int status = compile_ree_automatically(stream, builder);
      if (status)
        return status;
    }
    
  }
  
  node->type = type;
  node->set_node.set_node = builder->root;
  
  builder->root = rot;
  builder->node = nod;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;

}
  