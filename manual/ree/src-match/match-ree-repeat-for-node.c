#include <ree.h>

int match_ree_repeat_for_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){

  ree_size index = 0;
  
  for (; index < node->repeat_for_node.repeat_min; index++){
    
    bool fnd;
    int status1 = match_ree_node(stream, node->repeat_for_node.repeat_node, ree, &fnd);
    if (status1)
      return 1;
    
    if (fnd == false){
      *found = false;
      return 0;
    }
    
  }
  
  bool success = false;
  ree_stream successsm;
  ree_stream sm = *stream;
  
  bool fnd;
  int status1 = match_ree_node(stream, node->next, ree, &fnd);
  if (status1)
    return 1;
  
  if (fnd == true){
    success = true;
    successsm = *stream;
    confirm_ree_groups1(node); // groups
  }
  
  *stream = sm;
  
  for (; index < node->repeat_for_node.repeat_max; index++){
    
    ree_stream sm = *stream;
    
    bool fnd;
    int status1 = match_ree_node(stream, node->repeat_for_node.repeat_node, ree, &fnd);
    if (status1)
      return 1;
    
    if (fnd == true){
      
      ree_stream sm2 = *stream;
      
      bool fnd;
      int status1 = match_ree_node(stream, node->next, ree, &fnd);
      if (status1)
        return 1;
      
      if (fnd == true){
        success = true;
        successsm = *stream;
        confirm_ree_groups1(node); // groups
      }
      
      *stream = sm2;
      
    }
    
    else {
      
      if (success == true){
        *stream = successsm;
        confirm_ree_groups2(node); // groups
      }
      
      *found = success;
      return 0;
      
    }
    
  }
  
  if (success == true){
    *stream = successsm;
    confirm_ree_groups2(node); // groups
  }

  *found = success;
  return 0;
  
}
