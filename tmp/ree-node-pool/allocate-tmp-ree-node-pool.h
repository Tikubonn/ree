#define allocate_tmp_ree_node_pool(var, size)\
ree_size __ ## var ## _size = size;\
ree_node __ ## var ## _data[__ ## var ## _size];\
ree_node_pool __ ## var;\
ree_node_pool *var = &__ ## var;\
init_ree_node_pool(__ ## var ## _data, __ ## var ## _size, &__ ## var);
