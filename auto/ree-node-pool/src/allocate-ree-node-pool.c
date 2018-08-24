#include <ree.h>
#include <stdlib.h>

ree_node_pool *allocate_ree_node_pool (ree_size size){
  
  ree_node_pool *pool = malloc(sizeof(ree_node_pool));
  if (pool == NULL)
    return NULL;
  
  ree_node *sequence = malloc(sizeof(ree_node) * size);
  if (sequence == NULL){
    free(pool);
    return NULL;
  }
  
  init_ree_node_pool(sequence, size, pool);
  return pool;
  
}
