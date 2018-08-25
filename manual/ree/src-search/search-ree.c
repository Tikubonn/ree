#include <ree.h>

int __stdcall search_ree (ree_string *source, ree *ree, bool *found){
  
  ree_stream stream;
  init_ree_stream_from_string(source, &stream);
  
  while (!ree_stream_eof(&stream)){
    
    ree_stream sm = stream;
    ree_size beginning = ree_stream_index(&stream);
    
    bool fnd;
    int status1 = match_ree_node(&stream, ree->root, ree, &fnd);
    if (status1)
      return 1;
    
    if (fnd){
      *found = true;
      ree_size end = ree_stream_index(&stream);
      ree->match_beginning = beginning;
      ree->match_end = end;
      confirm_ree_groups1(ree->root); // groups
      return 0;
    }
    
    stream = sm;
    
    int status2 = seek_ree_stream(1, &stream);
    if (status2)
      return 1;
    
  }
  
  *found = false;
  return 0;
  
}
