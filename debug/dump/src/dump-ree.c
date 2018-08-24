#include <ree.h>
#include <stdio.h>

int __stdcall dump_ree (FILE *stream, ree *ree){
  return dump_ree_node(stream, ree->root, ree, 0);
}
