#include <ree.h>
#define min(a,b) ((a)<(b)?(a):(b))

ree_size read_ree_region (void *sequence, ree_size offset, ree_size size, ree_region *region, ree *ree){
	
	ree_size index;
	for (index = 0; index < size; index++){
		
		char character;
		int status1 = get_ree_region(index + offset, region, ree, &character);
		if (status1)
			return index;
		
		((char*)sequence)[index] = character;
		
	}
	
	return index;
	
}
