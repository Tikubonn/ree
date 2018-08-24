#include <ree.h>

ree_node_pool* __stdcall copy_ree_node_pool (ree_node_pool *pool){
  
  ree_size size = ree_node_pool_length(pool);
  
  ree_node_pool *pool2 = allocate_ree_node_pool(size);
  if (pool2 == NULL)
    return NULL;
  
  int status1 = copy_ree_node_pool_manually(pool, pool2);
  if (status1){
    free_ree_node_pool(pool2);
    return NULL;
  }
  
  return 0;
  
}
