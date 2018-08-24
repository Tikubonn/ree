#include <ree.h>

int __stdcall copy_ree_node_pool_manually (ree_node_pool *from, ree_node_pool *to){
  
  ree_size index;
  ree_size size = ree_node_pool_length(from);
  for (index = 0; index < size; index++){
    
    ree_node *nodea;
    int status1 = get_ree_node_pool(index, from, &nodea);
    if (status1)
      return 1;
    
    ree_node *nodeb = allocate_node_from_ree_node_pool(to);
    if (nodeb == NULL)
      return REE_NOT_ENOUGH_MEMORY;
    
    *nodeb = *nodea;
    
    int status2 = fix_ree_node(nodeb, to, from);
    if (status2)
      return 1;
    
  }
  
  return 0;
  
}
