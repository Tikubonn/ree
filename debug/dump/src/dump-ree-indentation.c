#include <ree.h>
#include <stdio.h>

int dump_ree_indentation (FILE *stream, ree_size indentation){

  while (indentation--){
    int status1 = putc(' ', stream);
    if (status1 == EOF)
      return 1;
  }
  
  return 0;
  
}
