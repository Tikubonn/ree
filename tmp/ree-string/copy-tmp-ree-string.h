#define copy_tmp_ree_string(var, source)\
ree_string *__ ## var ## _source = source;\
ree_size *__ ## var ## _source_size = ree_string_length(__ ## var ## __source);\
allocate_tmp_ree_string(var, __ ## var ## _source_size);\
copy_ree_string_manually(__ ## var ## _source, var);
