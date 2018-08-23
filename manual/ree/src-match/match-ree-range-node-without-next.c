#include <ree.h>

static int __byte (ree_stream *stream, ree_node *nodea, ree_node *nodeb, ree *ree, bool *found){
	
	char charactera;
	char characterb;
	
	int status1 = 
		get_ree_string(nodea->byte_node.index, ree->source, &charactera) || 
		get_ree_string(nodeb->byte_node.index, ree->source, &characterb);
	if (status1)
		return 1;
	
	char character = get_ree_stream(stream);
	if (character == REE_STREAM_EOF){
		*found = 0;
		return 0;
	}
	
	if (charactera <= character && 
		 	character <= characterb){
		*found = true;
		return 0;
	}
	
	*found = false;
	return 0;
	
}

static int __bytearray (ree_stream *stream, ree_node *nodea, ree_node *nodeb, ree *ree, bool *found){
	
	if (nodea->bytearray_node.index_end - nodea->bytearray_node.index_beginning != 
		  nodeb->bytearray_node.index_beginning - nodeb->bytearray_node.index_end)
		return 1;
	
	ree_stream sm = *stream;
	ree_size size = 
		nodea->bytearray_node.index_end - 
		nodea->bytearray_node.index_beginning;
	
	/* nodea = min nodeb = max */
	
	ree_size index;
	for (index = 0; index < size; index++){
		
		char charactera;
		char characterb;
		
		int status1 = 
			get_ree_string(nodea->bytearray_node.index_beginning + index, ree->source, &charactera) || 
			get_ree_string(nodeb->bytearray_node.index_beginning + index, ree->source, &characterb);
		if (status1)
			return 1;
		
		if (charactera < characterb){
		}
		
		if (characterb < charactera){
			ree_node *temp = nodea;
			nodea = nodeb;
			nodeb = temp;
			break;
		}
		
	}
	
	/* nodea < character */
	
	*stream = sm;
	ree_size index2;
	for (index2 = 0; index2 < size; index2++){
		
		char charactera;
		int status1 = get_ree_string(nodea->bytearray_node.index_beginning + index, ree->source, &charactera);
		if (status1)
			return 1;
		
		int character = get_ree_stream(stream);
		if (character == REE_STREAM_EOF){
			*found = false;
			return 0;
		}

		if (charactera > character){
			*found = false;
			return 0;
		}
		
		if (charactera == character){
		}
		
		if (charactera < character){
			break;
		}
		
	}
	
	/* character < nodeb */
	
	*stream = sm;
	ree_size index3;
	for (index3 = 0; index3 < size; index3){
		
		char charactera;
		int status1 = get_ree_string(nodeb->bytearray_node.index_beginning + index, ree->source, &charactera);
		if (status1)
			return 1;
		
		int character = get_ree_stream(stream);
		if (character == REE_STREAM_EOF){
			*found = false;
			return 0;
		}

		if (charactera > character){
			*found = false;
			return 0;
		}
		
		if (charactera == character){
		}
		
		if (charactera < character){
			break;
		}
		
	}
	
	/**/
	
	*stream = sm;
	
	int status10 = seek_ree_stream(size, stream);
	if (status10)
		return 1;
	
	*found = true;
	return 0;
	
}

int match_ree_range_node_without_next (ree_stream *stream, ree_node *node, ree *ree, bool *found){
	
	if (node->range_node.range_node1->type == REE_BYTE_NODE && 
			node->range_node.range_node2->type == REE_BYTE_NODE){
		return __byte(
			stream,
			node->range_node.range_node1, 
			node->range_node.range_node2,
			ree,
			found
		);
	}
	
	else 
	if (node->range_node.range_node1->type == REE_BYTEARRAY_NODE && 
		  node->range_node.range_node2->type == REE_BYTEARRAY_NODE){
		return __bytearray(
			stream,
			node->range_node.range_node1,
			node->range_node.range_node2,
			ree,
			found
		);
	}
	
	else {
		return 1;
	}
	
}
