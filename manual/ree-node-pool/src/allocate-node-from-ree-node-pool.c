#include <ree.h>

ree_node *allocate_node_from_ree_node_pool (ree_node_pool *pool){
  if (pool->end <= pool->index)
    return NULL;
  ree_node *node = &(pool->sequence[pool->index++]);
  default_ree_node(node);
  return node;
}
