#include <ree.h>

ree_string* __stdcall copy_ree_string (ree_string *string){
	
	ree_size size = ree_string_length(string);
	ree_string *string2 = allocate_ree_string(size);

	if (string2 == NULL)
		return NULL;
	
	int status1 = copy_ree_string_manually(string, string2);
	if (status1){
		free_ree_string(string2);
		return NULL;
	}
	
	return string2;
	
}
