#include <ree.h>

int seek_ree_stream (ree_size size, ree_stream *stream){
  stream->index += size;
  return 0;
}
