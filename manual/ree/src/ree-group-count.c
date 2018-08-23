#include <ree.h>

ree_size __stdcall ree_group_count (ree *ree){
	
	ree_size count = 0;
	ree_node *node = ree->group_root;
	while (node != NULL){
		node = node->group_node.next_group_node;
		count++;
	}
	
	return count;
	
}
