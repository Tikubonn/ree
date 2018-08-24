#define copy_tmp_ree_node_pool(var, pool)\
ree_node_pool *__ ## var ## _pool = pool;\
ree_size __ ## var ## _pool_size = ree_node_pool_length(__ ## var ## _pool);\
allocate_tmp_ree_node_pool(var, __ ## var ## _pool_size);\
copy_ree_node_pool_manually(var, __ ## var ## _pool);
