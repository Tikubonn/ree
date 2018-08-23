#include <ree.h>

int __stdcall get_ree_group (ree_size index, ree *ree, ree_region *region){

	ree_node *node = ree->group_root;
	while (node != NULL && index--)
		node = node->group_node.next_group_node;
	
	if (node == NULL)
		return 1;
	
	init_ree_region(
		node->group_node.match_beginning,
		node->group_node.match_end,
		region
	);
	
	return 0;
	
}
