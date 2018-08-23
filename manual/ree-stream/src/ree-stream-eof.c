#include <ree.h>

int ree_stream_eof (ree_stream *stream){
  return stream->end <= stream->index;
}
