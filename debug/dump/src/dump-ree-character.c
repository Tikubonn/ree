#include <ree.h>
#include <stdio.h>

void dump_ree_character (char character, FILE *stream){
  
  if (character <= 127){
    if (character <= 32){
      if (character == '\0'){
        fprintf(stream, "\\0");
      }
      else 
      if (character == '\a'){
        fprintf(stream, "\\a");
      }
      else 
      if (character == '\b'){
        fprintf(stream, "\\b");
      }
      else 
      if (character == '\t'){
        fprintf(stream, "\\t");
      }
      else 
      if (character == '\n'){
        fprintf(stream, "\\n");
      }
      else 
      if (character == '\v'){
        fprintf(stream, "\\v");
      }
      else 
      if (character == '\f'){
        fprintf(stream, "\\f");
      }
      else 
      if (character == '\r'){
        fprintf(stream, "\\r");
      }
      else 
      if (character == ' '){
        fprintf(stream, " ");
      }
      else {
        fprintf(stream, "\\x%02x", character);
      }
    }
    else 
    if (127 <= character){
      fprintf(stream, "\\x%02x", character);
    }
    else {
      fprintf(stream, "%c", character);
    }
  }

  else {
    fprintf(stream, "\\x%02x", character);
  }
  
}
