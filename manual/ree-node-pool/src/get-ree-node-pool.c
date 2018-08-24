#include <ree.h>

int get_ree_node_pool (ree_size index, ree_node_pool *pool, ree_node **node){
  if (pool->end <= index)
    return 1;
  *node = &(pool->sequence[index]);
  return 0;
}
