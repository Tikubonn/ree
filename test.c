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
dump_ree(stderr, ree);\
fprintf(stderr, "line of %lu: match_ree() caused error! (%d)\n", __LINE__, status2);\
abort();\
}\
if (found != fnd){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" matching result is not %s.\n", regexp, text, fnd ? "true" : "false");\
abort();\
}\
fprintf(stdout, "success: \"%s\" <= \"%s\" = %s\n", regexp, text, found ? "true" : "false");\
free_ree_string(source);\
free_ree(ree);\
free_ree_string(source2);\
}

#define test2(regexp, text, beg, ed) {\
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
if (found == false){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" unmatched.\n", regexp, text);\
abort();\
}\
ree_region region;\
get_ree_match(ree, &region);\
if (region.beginning != beg){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" (%d != %d) matched beginning position was unequal.", regexp, text, beg);\
abort();\
}\
if (region.end != ed){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" (%d != %d) matched end position was unequal.", regexp, text, ed);\
abort();\
}\
fprintf(stdout, "success: \"%s\" <= \"%s\" (%d, %d) = true\n", regexp, text, region.beginning, region.end);\
free_ree_string(source);\
free_ree(ree);\
free_ree_string(source2);\
}

#define test3(regexp, text, beg1, ed1, beg2, ed2) {\
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
if (found == false){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" unmatched.\n", regexp, text);\
abort();\
}\
ree_region region1;\
ree_region region2;\
int status3 = get_ree_group(0, ree, &region1);\
if (status3){\
dump_ree(stderr, ree);\
fprintf(stderr, "line of %lu: get_ree_group() caused error! (%d)\n", __LINE__, status3);\
}\
int status4 = get_ree_group(1, ree, &region2);\
if (status4){\
dump_ree(stderr, ree);\
fprintf(stderr, "line of %lu: get_ree_group() caused error! (%d)\n", __LINE__, status4);\
abort();\
}\
if (region1.beginning != beg1){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" (%d != %d) matched group1 beginning position was unequal.\n", regexp, text, region1.beginning, region1.end);\
abort();\
}\
if (region1.end != ed1){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" (%d != %d) matched group1 end position was unequal.\n", regexp, text, region1.beginning, region1.end);\
abort();\
}\
if (region2.beginning != beg2){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" (%d != %d) matched group2 beginning position was unequal.\n", regexp, text, region2.beginning, region2.end);\
abort();\
}\
if (region2.end != ed2){\
dump_ree(stderr, ree);\
fprintf(stderr, "failed: \"%s\" <= \"%s\" (%d != %d) matched group2 end position was unequal.\n", regexp, text, region2.beginning, region2.end);\
abort();\
}\
fprintf(stdout, "success: \"%s\" <= \"%s\" (%d, %d) (%d, %d) = true\n", regexp, text, region1.beginning, region1.end, region2.beginning, region2.end);\
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

  test2("mo.*!", "mo!mo!", 0, 6);
  test2("mo.*!", "moo!moo!", 0, 8);
  test2("mo.*!", "moco!moco!", 0, 10);
  test2("mo.*!", "monaco!monaco!", 0, 14);
    
  test2("mo.*?!", "mo!mo!", 0, 3);
  test2("mo.*?!", "moo!moo!", 0, 4);
  test2("mo.*?!", "moco!moco!", 0, 5);
  test2("mo.*?!", "monaco!monaco!", 0, 7);

  test2("mo.+!", "moo!moo!", 0, 8);
  test2("mo.+!", "moco!moco!", 0, 10);
  test2("mo.+!", "monaco!monaco!", 0, 14);
    
  test2("mo.+?!", "moo!moo!", 0, 4);
  test2("mo.+?!", "moco!moco!", 0, 5);
  test2("mo.+?!", "monaco!monaco!", 0, 7);
  
  test2("mo.{2}!", "moco!", 0, 5);
  test2("mo.{2}!", "moco!moco!", 0, 5);
  
  test2("mo.{2,128}!", "moco!", 0, 5);
  test2("mo.{2,128}!", "moco!moco!", 0, 10);
  
  test1("mo[o]+!", "moo!", true);
  test1("mo[ca]+!", "moca!", true);
  test1("mo[nac]+!", "monaca!", true);
  
  test1("mo[a-z]+!", "moo!", true);
  test1("mo[a-z]+!", "moca!", true);
  test1("mo[a-z]+!", "monaca!", true);

	test1("mo[o]!", "moo!", true);
	test1("mo[o]!", "moa!", false);
	
	test1("mo[a-z]!", "moo!", true);
	test1("mo[a-z]!", "mo0!", false);

	test1("mo[^o]!", "moo!", false);
	test1("mo[^o]!", "moa!", true);
	
	test1("mo[^a-z]!", "moo!", false);
	test1("mo[^a-z]!", "mo0!", true);
	
	test1("moco!|moca!", "moco!", true);
	test1("moco!|moca!", "moca!", true);
	test1("moco!|moca!", "mocc!", false);
	
	test1("moco!|moca!|moo!", "moco!", true);
	test1("moco!|moca!|moo!", "moca!", true);
	test1("moco!|moca!|moo!", "moo!", true);
	test1("moco!|moca!|moo!", "mono!", false);
  
	test1("(moco|chibi|nanashi)!", "moco!", true);
	test1("(moco|chibi|nanashi)!", "chibi!", true);
	test1("(moco|chibi|nanashi)!", "nanashi!", true);
	test1("(moco|chibi|nanashi)!", "tikubonn!", false);

	test1("<moco>!", "moco!", true);
	test1("<moco>!", "tikubonn!", false);
	
	test1("[<aaaa>-<zzzz>]", "aaaa", true);
	test1("[<aaaa>-<zzzz>]", "aazz", true);
	test1("[<aaaa>-<zzzz>]", "zzzz", true);
	test1("[<aaaa>-<zzzz>]", "aa00", true);
	test1("[<aaaa>-<zzzz>]", "00aa", false);
	
	test3("(<mo>*)(<co>*)", "moco", 0, 2, 2, 4);
	test3("(<mo>*)(<co>*)", "momoco", 0, 4, 4, 6);
	test3("(<mo>*(<co>*))", "moco", 0, 4, 2, 4);
	test3("(<mo>*(<co>*))", "momoco", 0, 6, 4, 6);
	
	test3("(<mo>+)(<co>+)", "moco", 0, 2, 2, 4);
	test3("(<mo>+)(<co>+)", "momoco", 0, 4, 4, 6);
	test3("(<mo>+(<co>+))", "moco", 0, 4, 2, 4);
	test3("(<mo>+(<co>+))", "momoco", 0, 6, 4, 6);
	
	test3("(<mo>{1,3})(<co>{1,3})", "moco", 0, 2, 2, 4);
	test3("(<mo>{1,3})(<co>{1,3})", "momoco", 0, 4, 4, 6);
	test3("(<mo>{1,3}(<co>{1,3}))", "moco", 0, 4, 2, 4);
	test3("(<mo>{1,3}(<co>{1,3}))", "momoco", 0, 6, 4, 6);
	
	test3("(<mo>*)(<co>*)", "moco....", 0, 2, 2, 4);
	test3("(<mo>*)(<co>*)", "momoco......", 0, 4, 4, 6);
	test3("(<mo>*(<co>*))", "moco....", 0, 4, 2, 4);
	test3("(<mo>*(<co>*))", "momoco......", 0, 6, 4, 6);
	
	test3("(<mo>+)(<co>+)", "moco....", 0, 2, 2, 4);
	test3("(<mo>+)(<co>+)", "momoco......", 0, 4, 4, 6);
	test3("(<mo>+(<co>+))", "moco....", 0, 4, 2, 4);
	test3("(<mo>+(<co>+))", "momoco......", 0, 6, 4, 6);
	
	test3("(<mo>{1,3})(<co>{1,3})", "moco....", 0, 2, 2, 4);
	test3("(<mo>{1,3})(<co>{1,3})", "momoco......", 0, 4, 4, 6);
	test3("(<mo>{1,3}(<co>{1,3}))", "moco....", 0, 4, 2, 4);
	test3("(<mo>{1,3}(<co>{1,3}))", "momoco......", 0, 6, 4, 6);
	
  return 0;
  
}
