#include <ree.h>

ree* __stdcall make_ree (ree_string *source){

	ree *ree = allocate_ree();
	if (ree == NULL)
		goto error1;
	
	ree_size size = ree_string_length(source);
	ree_node_pool *pool = allocate_ree_node_pool(size);
	if (pool == NULL)
		goto error2;
	
	ree_string *string = copy_ree_string(source);
	if (string == NULL)
		goto error3;
	
	init_ree(string, pool, ree);
	return ree;
	
	error3:
	free_ree_node_pool(pool);
	
	error2:
	free_ree(ree);
	
	error1:
	return NULL;
	
}
