#include <ree.h>

int fix_ree_repeat_necessary_node (ree_node *node, ree_node_pool *to, ree_node_pool *from){
	
	node->repeat_necessary_node.repeat_node = 
		(void*)(node->repeat_necessary_node.repeat_node) + 
		((intptr_t)(to->sequence) - 
		 (intptr_t)(from->sequence));
	
	return 0;

}
