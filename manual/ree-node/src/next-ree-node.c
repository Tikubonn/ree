#include <ree.h>

ree_node *next_ree_node (ree_node *node){
  if (node == NULL)
    return NULL;
  return node->next;
}
