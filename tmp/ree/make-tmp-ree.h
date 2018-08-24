#define make_tmp_ree(var, source)\
ree_string __ ## var ## _source = source;\
ree_size __ ## var ## _source_size = ree_string_length(__ ## var ## _source);\
copy_tmp_ree_string(__ ## var ## _string, __ ## var ## _source);\
allocate_tmp_ree_node_pool(__ ## var ## _pool, __ ## var ## _source_size);\
allocate_tmp_ree(var);\
init_ree(__ ## var ## _string, __ ## var ## _pool, var);
