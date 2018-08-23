#include <ree.h>

int connect_to_ree_builder_group_node (ree_node *node, ree_builder *builder){
  if (builder->group_root == NULL){
    builder->group_root = node;
  }
  if (builder->group_node == NULL){
    builder->group_node = node;
  }
  else {
    builder->group_node->group_node.next_group_node = node;
    builder->group_node = node;
  }
  return 0;
}
