#include <ree.h>
#include <stdio.h>

int compile_ree_range (ree_stream *stream, ree_builder *builder){
    
  int character = get_ree_stream(stream);
  if (character != '-')
    return REE_SYNTAX_ERROR;
  
  int status1 = compile_ree_automatically(stream, builder);
  if (status1)
    return status1;
  
  ree_node *nodea;
  ree_node *nodeb;
  
  int status2 = 
    pop_ree_builder_node(builder, &nodea) || 
    pop_ree_builder_node(builder, &nodeb);
  if (status2)
    return status2;

  if (nodea->type == REE_BYTE_NODE && 
      nodeb->type == REE_BYTE_NODE){
  }
  
  else if (
    nodea->type == REE_BYTEARRAY_NODE && 
    nodeb->type == REE_BYTEARRAY_NODE){
  }
  
  else {
    return 1;
  }
  
  ree_node *node = allocate_node_from_ree_node_pool(builder->ree->pool);
  if (node == NULL)
    return REE_NOT_ENOUGH_MEMORY;
  
  node->type = REE_RANGE_NODE;
  node->range_node.range_node1 = nodeb;
  node->range_node.range_node2 = nodea;
  
  int status10 = connect_to_ree_builder_node(node, builder);
  if (status10)
    return 1;
  return 0;
  
}
