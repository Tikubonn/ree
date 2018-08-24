#define allocate_tmp_ree(var)\
ree __ ## var;\
ree *var = &__ ## var;
