#include <ree.h>

/* I will rewrite here XD */

int pop_ree_builder_node (ree_builder *builder, ree_node **node){

  ree_node *nda = builder->node;
  if (nda == NULL)
    return 1;
  
  ree_node *ndb = nda->previous;
  if (ndb != NULL)
    ndb->next = NULL;
  nda->previous = NULL;
  
  *node = nda;
  builder->node = ndb;
  
  if (builder->root == nda)
    builder->root = NULL;
  
  return 0;
  
  /* if (builder->node == NULL)
    return 1;
  *node = builder->node;
  builder->node = previous_ree_node(builder->node);
  return 0; */
  
}
