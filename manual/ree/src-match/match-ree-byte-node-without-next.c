#include <ree.h>
#include <stdio.h>

int match_ree_byte_node_without_next (ree_stream *stream, ree_node *node, ree *ree, bool *found){
	
	int charactera = get_ree_stream(stream);
	if (charactera == REE_STREAM_EOF){
		*found = false;
		return 0;
	}
	
	char characterb;
	int status1 = get_ree_string(node->byte_node.index, ree->source, &characterb);
	if (status1)
		return 1;
	
	if (charactera == characterb){
		*found = true;
		return 0;
	}
	
	*found = false;
	return 0;
	
}
