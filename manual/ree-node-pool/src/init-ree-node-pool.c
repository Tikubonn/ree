#include <ree.h>

void __stdcall init_ree_node_pool (ree_node *sequence, ree_size size, ree_node_pool *pool){
	pool->sequence = sequence;
	pool->index = 0;
	pool->end = size;
}
