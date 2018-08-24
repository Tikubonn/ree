#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define REE_ERROR 1
#define REE_NOT_ENOUGH_MEMORY 2
#define REE_SYNTAX_ERROR 3

#define REE_SIZE_MIN 0
#define REE_SIZE_MAX SIZE_MAX

struct ree_node;
typedef size_t ree_size;

typedef struct {
  ree_size index;
} ree_byte_node;

typedef struct {
  ree_size index_beginning;
  ree_size index_end;
} ree_bytearray_node;

typedef struct {
  struct ree_node *repeat_node;
  ree_size repeat_min;
  ree_size repeat_max;
} ree_repeat_for_node;

typedef struct {
  struct ree_node *repeat_node;
  bool minimum;
} ree_repeat_necessary_node;

typedef struct {
  struct ree_node *repeat_node;
  bool minimum;
} ree_repeat_unnecessary_node;

typedef struct {
  struct ree_node *or_node1;
  struct ree_node *or_node2;
} ree_or_node;

typedef struct {
  struct ree_node *range_node1;
  struct ree_node *range_node2;
} ree_range_node;

typedef struct {
  struct ree_node *set_node;
} ree_set_node;

typedef struct {
  struct ree_node *group_node;
  struct ree_node *next_group_node;
  ree_size match_beginning;
  ree_size match_end;
  ree_size match_temp_beginning;
  ree_size match_temp_end;
} ree_group_node;

typedef struct {
  struct ree_node *unnecessary_node;
} ree_unnecessary_node;

#define REE_BYTE_NODE 0
#define REE_BYTEARRAY_NODE 1
#define REE_REPEAT_FOR_NODE 2
#define REE_REPEAT_NECESSARY_NODE 3
#define REE_REPEAT_UNNECESSARY_NODE 4
#define REE_OR_NODE 5
#define REE_RANGE_NODE 6
#define REE_INCLUSIVE_SET_NODE 7
#define REE_DECLUSIVE_SET_NODE 8
#define REE_GROUP_NODE 9
#define REE_UNNECESSARY_NODE 10
#define REE_ANY_NODE 11
#define REE_BEGINNING_NODE 12
#define REE_END_NODE 13

typedef struct ree_node {
  int type;
  union {
    ree_byte_node byte_node;
    ree_bytearray_node bytearray_node;
    ree_repeat_for_node repeat_for_node;
    ree_repeat_necessary_node repeat_necessary_node;
    ree_repeat_unnecessary_node repeat_unnecessary_node;
    ree_or_node or_node;
    ree_range_node range_node;
    ree_set_node set_node;
    ree_group_node group_node;
    ree_unnecessary_node unnecessary_node;
  };
  struct ree_node *next;
  struct ree_node *previous;
} ree_node;

typedef struct {
  char *sequence;
  ree_size size;
} ree_string;

#define REE_STREAM_EOF ((int)-1)

typedef struct {
  char *sequence;
  ree_size index;
  ree_size end;
} ree_stream;

typedef struct {
  ree_node *sequence;
  ree_size index;
  ree_size end;
} ree_node_pool;

typedef struct {
  ree_string *source;
  ree_node_pool *pool;
  ree_node *root;
  ree_node *group_root;
  // ree_size match_beginning;
  // ree_size match_end;
} ree;

typedef struct {
  ree *ree;
  ree_node *root;
  ree_node *node;
  ree_node *group_root;
  ree_node *group_node;
} ree_builder;

typedef struct {
  ree_size beginning;
  ree_size end;
} ree_region;
