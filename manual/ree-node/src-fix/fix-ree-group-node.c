#include <ree.h>

int fix_ree_group_node (ree_node *node, ree_node_pool *to, ree_node_pool *from){
	
	node->group_node.group_node = 
		(void*)(node->group_node.group_node) + 
		((intptr_t)(to->sequence) - 
		 (intptr_t)(from->sequence));
	
	node->group_node.next_group_node = 
		(void*)(node->group_node.next_group_node) + 
		((intptr_t)(to->sequence) - 
		 (intptr_t)(from->sequence));

	return 0;

}
