#include <ree.h>

int pop_ree_builder_node (ree_builder *builder, ree_node **node){
  if (builder->node == NULL)
    return 1;
  *node = builder->node;
  builder->node = previous_ree_node(builder->node);
  return 0;
}
