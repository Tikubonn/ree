#include <ree.h>

int compile_ree_unnecessary (ree_stream *stream, ree_builder *builder){
  
  int character = get_ree_stream(stream);
  if (character != '?')
    return REE_SYNTAX_ERROR;

  ree_node *nod;
  int status1 = pop_ree_builder_node(builder, &nod);
  if (status1)
    return 1;
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  node->type = REE_UNNECESSARY_NODE;
  node->unnecessary_node.unnecessary_node = nod;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;
  
}
