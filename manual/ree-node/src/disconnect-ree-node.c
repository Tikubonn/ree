#include <ree.h>

int disconnect_ree_node (ree_node *node){
  if (node == NULL) return 1;
  if (node->previous == NULL) return 1;
  node->previous->next = NULL;
  node->previous = NULL;
  return 0;
}
