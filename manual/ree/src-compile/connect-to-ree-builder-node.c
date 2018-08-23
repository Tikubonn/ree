#include <ree.h>

int connect_to_ree_builder_node (ree_node *node, ree_builder *builder){
  if (builder->root == NULL){
    builder->root = node;
  }
  if (builder->node == NULL){
    builder->node = node;
  }
  else {
    int status1 = connect_ree_node(builder->node, node);
    if (status1)
      return status1;
    builder->node = node;
  }
  return 0;
}
