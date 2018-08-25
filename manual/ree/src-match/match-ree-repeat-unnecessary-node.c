#include <ree.h>

static int __min (ree_stream *stream, ree_node *node, ree *ree, bool *found){

  ree_stream sm = *stream;
  
  bool fnd;
  int status1 = match_ree_node(stream, node->next, ree, &fnd);
  if (status1)
    return 1;
  
  if (fnd == true){
    *found = true;
		confirm_ree_groups1(node); // groups
		confirm_ree_groups2(node); // groups
    return 0;
  }
  
  *stream = sm;
  
  while (!ree_stream_eof(stream)){
    
    ree_stream sm = *stream;
    
    bool fnd;
    int status1 = match_ree_node(stream, node->repeat_unnecessary_node.repeat_node, ree, &fnd);
    if (status1)
      return 1;
    
    if (fnd == true){
      
      ree_stream sm2 = *stream;
      
      bool fnd;
      int status1 = match_ree_node(stream, node->next, ree, &fnd);
      if (status1)
        return 1;
      
      if (fnd == true){
        *found = true;
				confirm_ree_groups1(node); // groups
				confirm_ree_groups2(node); // groups
        return 0;
      }
      
      *stream = sm2;
      
    }
    
    else {
      *found = false;
      return 0;
    }
    
  }
  
  return match_ree_node(stream, node->next, ree, found);
  
}

static int __max (ree_stream *stream, ree_node *node, ree *ree, bool *found){

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
  
  while (!ree_stream_eof(stream)){
    
    bool fnd;
    int status1 = match_ree_node(stream, node->repeat_unnecessary_node.repeat_node, ree, &fnd);
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

int match_ree_repeat_unnecessary_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){
  if (node->repeat_unnecessary_node.minimum == true)
    return __min(stream, node, ree, found);
  return __max(stream, node, ree, found);
}
