#include <ree.h>

int fix_ree_repeat_for_node (ree_node *node, ree_node_pool *to, ree_node_pool *from){
	
	node->repeat_for_node.repeat_node = 
		(void*)(node->repeat_for_node.repeat_node) + 
		((intptr_t)(to->sequence) - 
		 (intptr_t)(from->sequence));
	
	return 0;

}
