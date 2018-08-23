#include <ree.h>
#include <stdlib.h>

extern void __stdcall free_ree_string (ree_string *string){
	free(string->sequence);
	free(string);
}
