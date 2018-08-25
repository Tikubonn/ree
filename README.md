
# Ree

Ree is a small C language's library that provide the [Regular Expression](https://en.wikipedia.org/wiki/Regular_expression) for byte array. this designed that run on one of allocated memory space. but this has not been optimized about memory spending and response speed, so you should use another library in your application if you need performance :D

```c
ree_string *string = make_ree_string0("hello (.+)!");
ree *ree = make_ree(string);
compile_ree(ree);

bool found;
ree_string *text = make_ree_string0("hello tikubonn!");
match_ree(text, ree, &found);

ree_size count = ree_group_count(ree); // 1

ree_region region;
get_ree_match(ree, &region); // hello ~ bonn!

ree_region region2;
get_ree_group(0, ree, &region2); // tikubonn
```

### Syntax

Ree has supported general basic syntaxes and one extend syntax :D

| Syntax | Description | 
| :--: | ---- | 
| `\` | escape one of character that is after this character. for example `\.` will be matched to `.`. |
| `^` | this character will be matched to beginning of string. be careful not first character of string! | 
| `$` | this character will be matched to end of string. be careful not last character of string! | 
| `.` | this character will be matching to any character. | 
| `*` | repeat one of previous expression until it could not match. if you wrote `?` after this expression, this will finish repeating as minimally. | 
| `+` | repeat one of previous expression until it could not match. if you wrote `?` after this expression, this will finish repeating as minimally. difference of `*` that at minimum this has to match once. | 
| `?` | if one of previous expression could not match then ignore it. | 
| `\|` | if previous expressions could not match, this will try next expressions. for example, `moco\|moca` will be match to `moco` or `moca`. | 
| `< ... >` | will be matched to same character array that in angle brackets. | 
| `[ ... ]` | this expression will be matched to one of character that in the brackets. if you wrote like `a-z`, it will be matched to one of character that in range of `a` to `z`. this library has supported `<...>` and `<...>-<...>` syntax in this expression. | 
| `[^ ... ]` | this expression will be matched to one of character that not in the brackets. if you wrote like `a-z`, it will be matched to one of character that not in range of `a` to `z`. this library has supported `<...>` and `<...>-<...>` syntax in this expression. | 
| `{min, max}` | repeat one of previous expression for `min` to `max`. if you wrote like `{n}`, repeat expression for `n`. | 
| `( ... )` | grouping expressions those in round brackets. grouped expressions will be one expression. you can get matched region of group after matching. | 
| Otherwise | will be matched to same character. | 

## API

### Data Types

this library provide some data types.

| Name | Description | 
| ---- | ---- | 
| `ree` | type of `ree` contain informations those are `ree_string` pointer for source of Regular Expression and `ree_node_pool` pointer for Node Collection for matching. you will use this type for searching and matching in this library :D | 
| `ree_string` | `red string` contain some informations those are address of byte array and its length. this type is used for input to some functions those in this library. |
| `ree_node_pool` | `ree_node_pool` contain some informations those are address of `ree_node` array, its length and and etc. this type used to allocating node for some functions those in this library. | 
| `ree_region` | this data type contain some position informations those are matched result. | 

### Manual Functions 

you must give there functions memory for running .
for example, there functions are useful if you want run this library on allocated memory that is managed by GC :D

```c
char source_data[] = "hello (.+)!";
ree_string source;
init_ree_string(source_data, sizeof(source_data), &source);

ree_node pool_data[sizeof(source_data)];
ree_node_pool pool;
init_ree_node_pool(pool_data, sizeof(pool_data), &pool);

ree ree;
init_ree(&source, &pool, &ree);

char text_data[] = "hello tikubonn!";
ree_string text;
init_ree_string(text_data, sizeof(text_data), &text);

bool found;
match_ree(&text, &ree, &found);
```

| Function | Description | 
| ---- | ---- |
| `void init_ree_string (char*, ree_size, ree_string *string);` | construct `string` with byte array. this function will always success. | 
| `void init_ree_string0 (char*, ree_string *string);` | construct `string` with byte array that last element must be `0`. this function will always success. | 
| `int get_ree_string (ree_size index, ree_string *string, char *character);` | write one element to `character`. if `index` was overflowed or caused error, this function return `REE_ERROR`. | 
| `ree_size ree_string_length (ree_string *string);` | return length of `string`. | 
| `int copy_ree_string_manually (ree_string *from, ree_string *to);` | copy `from` contents to `to`. if `to` has not enough space, this return `REE_NOT_ENOUGH_MEMORY`. if caused error in this function, this return `REE_ERROR`, otherwise `0`. | 

| Function | Description | 
| ---- | ---- |
| `void init_ree_pool (ree_node*, ree_size, ree_node_pool*);` | construct `ree_node_pool` with `ree_node` array. this function will always success. |
| `int copy_ree_pool_manually (ree_node_pool*, ree_node_pool*);` | copy `from` nodes to `to`. if `to` has not enough space, this return `REE_NOT_ENOUGH_MEMORY`. if caused error in this function, this return `REE_ERROR`, otherwise `0`. |

| Function | Description | 
| ---- | ---- |
| `void init_ree (ree_string*, ree_node_pool*, ree*);` | construct `ree` with `ree_string` pointer and `ree_node_pool` pointer. this function will always success. |
| `int match_ree (ree_string *text, ree*, bool *found);` | this function try matching `text` by `ree`. `found` will be `true` if matching was success, otherwise `false`. if caused error in this function, this function will return `REE_ERROR`, otherwise `0`. | 
| `int search_ree (ree_string *text, ree*, bool *found);` | this function try searching `text` by `ree`. `found` will be `true` if matching was success, otherwise `false`. if caused error in this function, this function will return `REE_ERROR`, otherwise `0`. | 
| `ree_size ree_group_count (ree *ree);` | return length of groups in `ree`. | 
| `int get_ree_group (ree_size id, ree *ree, ree_region *region);` | write region information to `region` from matched group. if `id` was overflowed or caused error, this function return `REE_ERROR`. |
| `int get_ree_match (ree *ree, ree_region *region);` | write region information to `region` from `ree`. if caused error, this function return `REE_ERROR`, otherwise `0`. |

| Function | Description | 
| ---- | ---- |
| `ree_size ree_region_length (ree_region *region);` | return length of `region`. | 
| `int get_ree_region (ree_size index, ree_region *region, ree *ree, char *character);` | write one element to `character` from `region`. if `index` was overflowed or caused error, this function return `REE_ERROR`. |
| `int read_ree_region (void *sequence, ree_size offset, ree_size size, ree_region*, ree*);` | write byte array to `sequence` from `region`. this function will return wrote size as integer. |

### Automatic Functions 

there functions will allocate memory automatically with `malloc` for running. so you should free allocated memory that is unnecessary manually :D

```c
ree_string *source = make_ree_string("hello (.+)!");
ree *ree = make_ree(source);
compile_ree(ree);

bool found;
ree_string *text = make_ree_string0("hello tikubonn!");
match_ree(text, ree, &found);
```

| Function | Description | 
| ---- | ---- | 
| `ree_string *make_ree_string (char*, ree_size);` | make `ree_string` instance with byte array. if caused error in this function, this return `NULL`. | 
| `ree_string *make_ree_string0 (char*);` | make `ree_string` instance with byte array. if caused error in this function, this return `NULL`. | 
| `ree_string *copy_ree_string (ree_string*);` | copy `ree_string` instance by argument. if caused error in this function, this return `NULL`. | 
| `void free_ree_string (ree_string*);` | free a maken `ree_string` instance. this function will always success. | 

| Function | Description | 
| ---- | ---- | 
| `ree_node_pool *allocate_ree_node_pool (ree_size);` | make `ree_node_pool` instance with argument. if caused error in this function, this return `NULL`. | 
| `ree_node_pool *copy_ree_node_pool (ree_node_pool*);` | copy `ree_node_pool` instance by argument. if caused error in this function, this return `NULL`. | 
| `void free_ree_node_pool (ree_node_pool*);` | free a maken `ree_node_pool` instance. this function will always success. | 

| Function | Description | 
| ---- | ---- | 
| `ree *make_ree (ree_string*);` | make a `ree` instance with argument. if caused error in this function, this return `NULL`. | 
| `void free_ree (ree*);` | free a maken `ree` instance. this function will always success. | 

### Temporary Macros 

there functions allocate memory from stack frame automatically. so you dont need freeing unnecessary memory. but be careful! if your process dont have enough memory, cause memory error (segmentation fault) XD Planned for use.

```c
make_tmp_ree_string0(source, "hello (.+)!");
make_tmp_ree(ree, source);
compile_ree(ree);

bool found;
make_tmp_ree_string0(text, "hello tikubonn!");
match_ree(text, ree, &found);
```

| Macro | Description | 
| ---- | ---- |
| `make_tmp_ree_string (var, char*, ree_size)` | |
| `make_tmp_ree_string0 (var, char*)` | |
| `copy_tmp_ree_string (var, ree_string*)` | |

| Macro | Description | 
| ---- | ---- |
| `make_tmp_ree_node_pool (var, ree_size)` | |
| `copy_tmp_ree_node_pool (var, ree_node_pool*)` | |

| Macro | Description | 
| ---- | ---- |
| `make_tmp_ree (var, ree_string*)` | |
| `copy_tmp_ree (var, ree*)` | |

## Where I can get the stable one? 

this library has not reached version of alpha yet. so please wait for developed completely. so you dont have to tell me the found bug :D
