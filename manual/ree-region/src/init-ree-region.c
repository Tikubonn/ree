#include <ree.h>

void init_ree_region (ree_size beginning, ree_size end, ree_region *region){
  region->beginning = beginning;
  region->end = end;
}
