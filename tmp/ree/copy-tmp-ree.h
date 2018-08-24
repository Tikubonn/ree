#define copy_tmp_ree(var, ree)\
ree *__ ## var ## _ree = ree;\
copy_tmp_ree_string(__ ## var ## _string, __ ## var ## _ree->string);\
copy_tmp_ree_node_pool(__ ## var ## _pool, __ ## var ## _ree->pool);\
allocate_tmp_ree(var);\
init_ree(__ ## var ## _string, __ ## var ## _pool, var);
