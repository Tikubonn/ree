#include <ree.h>

ree_size __stdcall ree_region_length (ree_region *region){
	/* return 
		region->end < region->beginning ? 0 :
		region->end - region->beginning; */
	return region->end - region->beginning;
}
