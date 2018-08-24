#include <ree.h>

void __stdcall clear_ree_node_pool (ree_node_pool *pool){
  pool->index = 0;
}
