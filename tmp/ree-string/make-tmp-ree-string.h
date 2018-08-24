#define make_tmp_ree_string(var, source, size)\
ree_string *__ ## var ## _source = source;\
ree_size *__ ## var ## _source_size = size;\
allocate_tmp_ree_string(var, __ ## var ## _source_size);\
init_ree_string(__ ## var ## _source, __ ## var ## _source_size, var);
