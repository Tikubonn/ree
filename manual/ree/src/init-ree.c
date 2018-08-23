#include <ree.h>

void __stdcall init_ree (ree_string *source, ree_node_pool *pool, ree *ree){
  ree->source = source;
  ree->pool = pool;
  ree->root = NULL;
  ree->group_root = NULL;
}
