#include <ree.h>
#include <stdlib.h>

void __stdcall free_ree_node_pool (ree_node_pool *pool){
  free(pool->sequence);
  free(pool);
}
