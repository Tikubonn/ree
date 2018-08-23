#include <ree.h>

int fix_ree_set_node (ree_node *node, ree_node_pool *to, ree_node_pool *from){
	
	node->set_node.set_node = 
		(void*)(node->set_node.set_node) + 
		((intptr_t)(to->sequence) - 
		 (intptr_t)(from->sequence));
	
	return 0;

}
