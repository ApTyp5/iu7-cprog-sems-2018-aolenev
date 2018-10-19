#include "strIU7ng.h"

int strIU7ng_cmp(strIU7ng s1, strIU7ng s2)
{
    int i;
    for (i = 0; i < s1.len && i < s2.len && s1.head[i] == s2.head[i]; i++);
    return (i == s1.len ? '\0' : s1.head[i]) - (i == s2.len ? '\0' : s2.head[i]);
}

void strIU7ng_replace_test1(int *success_tests)
{
    strIU7ng str1 = {0, NULL};
    strIU7ng search1 = {0, NULL};
    strIU7ng replace1 = {0, NULL};
    
    strIU7ng expect_str = strIU7ng_replace(str1, search1, replace1);
    if (!strIU7ng_cmp(expect_str, str1))
        (*success_tests)++;
    
    strIU7ng_free(&expect_str);
}

void strIU7ng_replace_test2(int *success_tests)
{
    strIU7ng str2 = strIU7ng_create("grandgrandpa");
    strIU7ng search2 = strIU7ng_create("grand");
    strIU7ng replace2 = strIU7ng_create("grand");
    
    strIU7ng expect_str = strIU7ng_replace(str2, search2, replace2);
    if (!strIU7ng_cmp(expect_str, str2))
        (*success_tests)++;
    
    strIU7ng_free(&str2);
    strIU7ng_free(&search2);
    strIU7ng_free(&replace2);
    strIU7ng_free(&expect_str);
}

void strIU7ng_replace_test3(int *success_tests)
{
    strIU7ng str3_res = strIU7ng_create("ability");
    strIU7ng str3 = strIU7ng_create("able");
    strIU7ng search3 = strIU7ng_create("le");
    strIU7ng replace3 = strIU7ng_create("ility");
    
    strIU7ng expect_str = strIU7ng_replace(str3, search3, replace3);
    if (!strIU7ng_cmp(expect_str, str3_res))
        (*success_tests)++;
    
    strIU7ng_free(&str3);
    strIU7ng_free(&str3_res);
    strIU7ng_free(&search3);
    strIU7ng_free(&replace3);
    strIU7ng_free(&expect_str);
}

int main(void)
{
    int success_tests = 0;
    int count_tests = 3;
    
    strIU7ng_replace_test1(&success_tests);
    strIU7ng_replace_test2(&success_tests);
    strIU7ng_replace_test3(&success_tests);
    
    printf("%d of  %d tests passed successfully.\n", success_tests, count_tests);
    
    return 0;
}
