#include <ree.h>

void __stdcall get_ree_match (ree *ree, ree_region *region){
  region->beginning = ree->match_beginning;
  region->end = ree->match_end;
}
