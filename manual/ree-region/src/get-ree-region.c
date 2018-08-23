#include <ree.h>

int __stdcall get_ree_region (ree_size index, ree_region *region, ree *ree, char *character){
	
	ree_size size = ree_region_length(region);
	if (size <= index)
		return 1;
	
	int status1 = get_ree_string(region->beginning + index, ree->source, character);
	if (status1)
		return 1;
	return 0;
	
}
