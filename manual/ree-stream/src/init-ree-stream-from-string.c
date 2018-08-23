#include <ree.h>

void init_ree_stream_from_string (ree_string *string, ree_stream *stream){
  init_ree_stream(string->sequence, string->size, stream);
}
