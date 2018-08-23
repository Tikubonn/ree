#include <ree.h>

ree_node *previous_ree_node (ree_node *node){
  if (node == NULL)
    return NULL;
  return node->previous;
}
