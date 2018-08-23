#include <ree.h>

int compile_ree_automatically (ree_stream *stream, ree_builder *builder){
  
  int character = peek_ree_stream(stream);
  
  switch (character){
  
    case REE_STREAM_EOF:
    case '>':
    case '}':
    case ']':
    case ')': 
      return 1;
    
    case '^': {
      int status = compile_ree_beginning(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '$': {
      int status = compile_ree_end(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '.': {
      int status = compile_ree_any(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '*': {
      int status = compile_ree_repeat_unnecessary(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '+': {
      int status = compile_ree_repeat_necessary(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '?': {
      int status = compile_ree_unnecessary(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '<': {
      int status = compile_ree_bytearray(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '{': {
      int status = compile_ree_repeat_for(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '[': {
      int status = compile_ree_set(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '(': {
      int status = compile_ree_group(stream, builder);
      if (status)
        return status;
			break;
    }
    
    case '|': {
      int status = compile_ree_or(stream, builder);
      if (status)
        return status;
			break;
    }
    
    default: {
      int status = compile_ree_byte(stream, builder);
      if (status)
        return status;
			break;
    }
    
  }

}
