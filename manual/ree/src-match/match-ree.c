#include <ree.h>

int __stdcall match_ree (ree_string *source, ree *ree, bool *found){
  
  ree_stream stream;
  init_ree_stream_from_string(source, &stream);
  
	ree_size beginning = ree_stream_index(&stream); // 0
	
  int status1 = match_ree_node(&stream, ree->root, ree, found);
  if (status1)
    return 1;
	
	confirm_ree_groups1(ree->root); // groups
	
	ree_size end = ree_stream_index(&stream);
	ree->match_beginning = beginning;
	ree->match_end = end;
	
  return 0;
  
}
