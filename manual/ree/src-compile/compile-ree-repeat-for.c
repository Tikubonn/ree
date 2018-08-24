#include <ree.h>

static int __whitespace (ree_stream *stream){
  while (peek_ree_stream(stream) == ' '){
    int status1 = seek_ree_stream(1, stream);
    if (status1)
      return 1;
  }
  return 0;
}

static int __number (ree_stream *stream, ree_size *number){
  ree_size num = 0;
  while (1){
    int character = peek_ree_stream(stream);
    if ('0' <= character && character <= '9'){
      if ((REE_SIZE_MAX / 10) < num)
        return 1;
      num *= 10;
      num += character - '0';
      int status1 = seek_ree_stream(1, stream);
      if (status1)
        return 1;
    }
    else {
      break;
    }
  }
  *number = num;
  return 0;
}

int compile_ree_repeat_for (ree_stream *stream, ree_builder *builder){
  
  int character1 = get_ree_stream(stream);
  if (character1 != '{')
    return 1;
  
  ree_size repeat_min;
  ree_size repeat_max;
  
  int status1 = 
    __whitespace(stream) || 
    __number(stream, &repeat_min) || 
    __whitespace(stream);
  if (status1)
    return 1;
  
  int character2 = get_ree_stream(stream);
  if (character2 == ','){
    int status1 = 
      __whitespace(stream) || 
      __number(stream, &repeat_max) || 
      __whitespace(stream);
    if (status1)
      return 1;
    
    int character = get_ree_stream(stream);
    if (character != '}')
      return 1;
  }
  
  if (character2 == '}'){
    repeat_max = repeat_min;
  }
  
  ree_node *nd;
  int status10 = pop_ree_builder_node(builder, &nd);
  if (status10)
    return 1;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return 1;
  
  node->type = REE_REPEAT_FOR_NODE;
  node->repeat_for_node.repeat_min = repeat_min;
  node->repeat_for_node.repeat_max = repeat_max;
  node->repeat_for_node.repeat_node = nd;
  
  int status11 = connect_to_ree_builder_node(node, builder);
  if (status11)
    return 1;
  return 0;

}
