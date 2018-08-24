#include <ree.h>
#include <stdio.h>
#include <stdlib.h>

#define test1(regexp, text, fnd) {\
ree_string *source = make_ree_string0(regexp);\
ree *ree = make_ree(source);\
int status1 = compile_ree(ree);\
if (status1){\
fprintf(stderr, "line of %lu: compile_ree() caused error! (%d)\n", __LINE__, status1);\
abort();\
}\
bool found;\
ree_string *source2 = make_ree_string0(text);\
int status2 = match_ree(source2, ree, &found);\
if (status2){\
fprintf(stderr, "line of %lu: match_ree() caused error! (%d)\n", __LINE__, status1);\
abort();\
}\
if (found != fnd){\
fprintf(stderr, "failed: \"%s\" <= \"%s\" matching result is not %s.\n", regexp, text, fnd ? "true" : "false");\
abort();\
}\
fprintf(stdout, "success: \"%s\" <= \"%s\" = %s\n", regexp, text, found ? "true" : "false");\
free_ree_string(source);\
free_ree(ree);\
free_ree_string(source2);\
}

int main (){
  
  test1("mo..!", "moco!", true);
  test1("mo..!", "mooo!", true);
  
  test1("mo.*!", "mo!", true);
  test1("mo.*!", "moo!", true);
  test1("mo.*!", "moco!", true);
  test1("mo.*!", "monaco!", true);
    
  test1("mo.*?!", "mo!", true);
  test1("mo.*?!", "moo!", true);
  test1("mo.*?!", "moco!", true);
  test1("mo.*?!", "monaco!", true);
    
  test1("mo.+!", "mo!", false);
  test1("mo.+!", "moo!", true);
  test1("mo.+!", "moco!", true);
  test1("mo.+!", "monaco!", true);
    
  test1("mo.+?!", "mo!", false);
  test1("mo.+?!", "moo!", true);
  test1("mo.+?!", "moco!", true);
  test1("mo.+?!", "monaco!", true);

  test1("mo.{1,2}!", "mo!", false);
  test1("mo.{1,2}!", "moo!", true);
  test1("mo.{1,2}!", "moco!", true);
  test1("mo.{1,2}!", "monaco!", false);
  
  test1("mo.{2}!", "mo!", false);
  test1("mo.{2}!", "moo!", false);
  test1("mo.{2}!", "moco!", true);
  test1("mo.{2}!", "monaco!", false);
  
  return 0;
  
}
