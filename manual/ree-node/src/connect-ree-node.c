#include <ree.h>

int connect_ree_node (ree_node *nodea, ree_node *nodeb){
  if (nodea == NULL) return 1;
  if (nodeb == NULL) return 1;
  nodea->next = nodeb;
  nodeb->previous = nodea;
  return 0;
}

