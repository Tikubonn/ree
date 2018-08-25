#include <ree.h>

int confirm_ree_groups1 (ree_node *node){
  
  if (node == NULL)
    return 0;
  
  if (node->type == REE_GROUP_NODE){
    node->group_node.match_beginning = node->group_node.match_temp_beginning;
    node->group_node.match_end = node->group_node.match_temp_end;
    return 
      confirm_ree_groups1(node->group_node.group_node) || 
      confirm_ree_groups1(node->next);
  }
  
  else
  if (node->type == REE_REPEAT_FOR_NODE){
    return 
      confirm_ree_groups1(node->repeat_for_node.repeat_node) || 
      confirm_ree_groups1(node->next);
  }
  
  else
  if (node->type == REE_REPEAT_NECESSARY_NODE){
    return 
      confirm_ree_groups1(node->repeat_necessary_node.repeat_node) || 
      confirm_ree_groups1(node->next);
  }
  
  else
  if (node->type == REE_REPEAT_UNNECESSARY_NODE){
    return 
      confirm_ree_groups1(node->repeat_unnecessary_node.repeat_node) || 
      confirm_ree_groups1(node->next);
  }

  else
  if (node->type == REE_OR_NODE){
    return 
      confirm_ree_groups1(node->or_node.or_node1) || 
      confirm_ree_groups1(node->or_node.or_node2) || 
      confirm_ree_groups1(node->next);
  }

  else 
  if (node->type == REE_UNNECESSARY_NODE){
    return 
      confirm_ree_groups1(node->unnecessary_node.unnecessary_node) || 
      confirm_ree_groups1(node->next);
  }
  
  else {
    return confirm_ree_groups1(node->next);
  }
  
}
