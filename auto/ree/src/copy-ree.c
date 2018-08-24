#include <ree.h>

ree* __stdcall copy_ree (ree *re){
  
  ree *re2 = allocate_ree();
  if (re2 == NULL)
    goto error1;
  
  ree_node_pool *pool = copy_ree_node_pool(re->pool);
  if (pool == NULL)
    goto error2;
  
  ree_string *string = copy_ree_string(re->source);
  if (string == NULL)
    goto error3;
  
  init_ree(string, pool, re2);
  return re2;
  
  error3:
  free_ree_node_pool(pool);
  
  error2:
  free_ree(re2);
  
  error1:
  return NULL;
  
}
