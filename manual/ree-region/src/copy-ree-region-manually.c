#include <ree.h>

int __stdcall copy_ree_region_manually (ree_region *region, ree *ree, ree_string *string){

	ree_size sizea = ree_region_length(region);
	ree_size sizeb = ree_string_length(string);

	if (sizea != sizeb)
		return 1;
	
	ree_size index;
	for (index = 0; index < sizea; index++){
		
		char character;
		int status1 = get_ree_region(index, region, ree, &character);
		if (status1)
			return 1;
		
		string->sequence[index] = character;
			
	}
	
	return 0;
	
}
