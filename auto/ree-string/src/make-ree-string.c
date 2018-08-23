#include <ree.h>

extern ree_string* __stdcall make_ree_string (char *sequence, ree_size size){
	
	ree_string *string = allocate_ree_string(size);
	if (string == NULL)
		return NULL;
	
	ree_size index;
	for (index = 0; index < size; index++){
		string->sequence[index] = sequence[index];
	}
	
	return string;
	
}
