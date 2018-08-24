#include <ree.h>

ree_size __stdcall ree_node_pool_length (ree_node_pool *pool){
  return pool->index;
}
