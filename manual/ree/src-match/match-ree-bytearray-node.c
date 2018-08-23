#include <ree.h>

int match_ree_bytearray_node (ree_stream *stream, ree_node *node, ree *ree, bool *found){

	bool fnd;
	int status1 = match_ree_bytearray_node_without_next(stream, node, ree, &fnd);
	if (status1)
		return 1;
	
	if (fnd == false){
		*found = false;
		return 0;
	}

	return match_ree_node(stream, node->next, ree, found);
	
}
