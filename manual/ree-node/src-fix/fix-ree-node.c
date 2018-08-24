#include <ree.h>

int fix_ree_node (ree_node *node, ree_node_pool *to, ree_node_pool *from){
  
  node->next = 
    (void*)(node->next) + 
    ((intptr_t)(to->sequence) - 
     (intptr_t)(from->sequence));

  node->previous = 
    (void*)(node->next) + 
    ((intptr_t)(to->sequence) - 
     (intptr_t)(from->sequence));
  
  switch (node->type){
    case REE_GROUP_NODE:
      return fix_ree_group_node(node, to, from);
    case REE_REPEAT_FOR_NODE:
      return fix_ree_repeat_for_node(node, to, from);
    case REE_REPEAT_NECESSARY_NODE:
      return fix_ree_repeat_necessary_node(node, to, from);
    case REE_REPEAT_UNNECESSARY_NODE:
      return fix_ree_repeat_unnecessary_node(node, to, from);
    case REE_INCLUSIVE_SET_NODE:
      return fix_ree_set_node(node, to, from);
    case REE_DECLUSIVE_SET_NODE:
      return fix_ree_set_node(node, to, from);
    case REE_UNNECESSARY_NODE:
      return fix_ree_unnecessary_node(node, to, from);
    default:
      return 0;
  }
  
}
