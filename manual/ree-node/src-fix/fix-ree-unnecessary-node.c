#include <ree.h>

int fix_ree_unnecessary_node (ree_node *node, ree_node_pool *to, ree_node_pool *from){

	node->unnecessary_node.unnecessary_node = 
		(void*)(node->unnecessary_node.unnecessary_node) + 
		((intptr_t)(to->sequence) - 
		 (intptr_t)(from->sequence));

	return 0;

}
