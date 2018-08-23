#include <ree.h>

void init_ree_stream (char *sequence, ree_size size, ree_stream *stream){
  stream->sequence = sequence;
  stream->index = 0;
  stream->end = size;
}
