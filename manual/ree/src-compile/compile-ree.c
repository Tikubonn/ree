#include <ree.h>

int compile_ree (ree *ree){
  
  ree_stream stream;
  init_ree_stream_from_string(ree->source, &stream);
  
  ree_builder builder;
  builder.ree = ree;
  builder.root = NULL;
  builder.node = NULL;
  builder.group_root = NULL;
  builder.group_node = NULL;
  
  while (!ree_stream_eof(&stream)){
    int status1 = compile_ree_automatically(&stream, &builder);
    if (status1)
      return status1;
  }
  
  ree->root = builder.root;
  ree->group_root = builder.group_root;

  return 0;

}
