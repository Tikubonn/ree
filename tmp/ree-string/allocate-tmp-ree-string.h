#define allocate_tmp_ree_string(var, size)\
ree_size __ ## var ## _size = size;\
char __ ## var ## _data[__ ## var ## _size];\
ree_string __ ## var;\
ree_string *var = &__ ## var;\
init_ree_string(__ ## var ## _data, __ ## var ## _size, &__ ## var);
