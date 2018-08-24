#include <ree.h>
#include <stdlib.h>

void __stdcall free_ree (ree *ree){
  free(ree);
}
