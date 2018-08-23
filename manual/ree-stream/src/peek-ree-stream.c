#include <ree.h>

int peek_ree_stream (ree_stream *stream){
  if (stream->end <= stream->index)
    return REE_STREAM_EOF;
  return stream->sequence[stream->index];
}
