#include <ree.h>

int compile_ree_repeat_unnecessary (ree_stream *stream, ree_builder *builder){
  
  int character1 = get_ree_stream(stream);
  if (character1 != '*')
    return REE_SYNTAX_ERROR;
  
  bool minimum = false;
  int character2 = peek_ree_stream(stream);
  if (character2 == '?'){
    int status1 = seek_ree_stream(1, stream);
    if (status1)
      return 1;
    minimum = true;
  }
  
  ree_node *nod;
  int status1 = pop_ree_builder_node(builder, &nod);
  if (status1)
    return 1;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  node->type = REE_REPEAT_UNNECESSARY_NODE;
  node->repeat_unnecessary_node.repeat_node = nod;
  node->repeat_unnecessary_node.minimum = minimum;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;

}
