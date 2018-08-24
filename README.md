
# Ree

Ree is a small C language's library that provide the regular expression for binary. this designed that run on one of allocated memory space. but this has not been optimized about memory spending and response speed, so you should use another library in your application if you need performance :D

```c
ree_string *string = make_ree_string0("hello (.+)!");
ree *ree = make_ree(string);
compile_ree(ree);

ree_string *text = make_ree_string0("hello tikubonn!");
bool found;
match_ree(text, ree, &found);

ree_region region;
get_ree_match(ree, &region); // hello ~ bonn!

ree_region region2;
get_ree_group(0, ree, &region2); // tikubonn

ree_size count = ree_group_count(ree); // 1
```

## Where I can get the stable one? 

this library has not reached version of alpha yet. so please wait for developed completely. so you dont have to tell me the found bug :D
