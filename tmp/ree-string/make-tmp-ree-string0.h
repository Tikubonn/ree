#define make_tmp_ree_string0(var, source)\
char *__ ## var ## _source = source;\
ree_size __ ## var ## _source_size = 0;\
for (*__ ## var ## _source++){\
__ ## var ## _source_size++;\
}\
allocate_tmp_ree_string(var, __ ## var ## _source_size);\
ree_size __ ## var ## _source_index;\
for (\__ ## var ## _source_index = 0;\
__ ## var ## _source_index < __ ## var ## _source_size;\
__ ## var ## _source_index++){\
var->sequence[__ ## var ## _source_index]=\
__ ## var ## _source[__ ## var ## _source_index];\
}
