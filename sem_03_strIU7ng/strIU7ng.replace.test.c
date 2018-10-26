#include "strIU7ng.h"

int strIU7ng_cmp(strIU7ng s1, strIU7ng s2)
{
    int i; 
    for (i = 0; i < s1.len && i < s2.len && s1.head[i] == s2.head[i]; i++);
    return (i == s1.len ? '\0' : s1.head[i]) - (i == s2.len ? '\0' : s2.head[i]);
}

int strIU7ng_replace_test1()
{
    strIU7ng str = {0, NULL};
    strIU7ng search = {0, NULL};
    strIU7ng replace = {0, NULL};
    strIU7ng expected = {0, NULL};

    strIU7ng result = strIU7ng_replace(str, search, replace);

    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int strIU7ng_replace_test2()
{
    strIU7ng str = strIU7ng_create("bbbbb");
    strIU7ng search = strIU7ng_create("bbb");
    strIU7ng replace = strIU7ng_create("a"); 
    strIU7ng expected = strIU7ng_create("abb");

    strIU7ng result = strIU7ng_replace(str, search, replace);

    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int strIU7ng_replace_test3()
{
    strIU7ng str = strIU7ng_create("bbbb");
    strIU7ng search = strIU7ng_create("b");
    strIU7ng replace = strIU7ng_create("a");
    strIU7ng expected = strIU7ng_create("aaaa");

    strIU7ng result = strIU7ng_replace(str, search, replace);


    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int strIU7ng_replace_test4()
{
    strIU7ng str = strIU7ng_create("bbbb");
    strIU7ng search = strIU7ng_create("b");
    strIU7ng replace = strIU7ng_create("aaaa");
    strIU7ng expected = strIU7ng_create("aaaaaaaaaaaaaaaa");

    strIU7ng result = strIU7ng_replace(str, search, replace);

    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int strIU7ng_replace_test5()
{
    strIU7ng str = strIU7ng_create("bbb");
    strIU7ng search = strIU7ng_create("bb");
    strIU7ng replace = strIU7ng_create("");
    strIU7ng expected = strIU7ng_create("b");

    strIU7ng result = strIU7ng_replace(str, search, replace);

    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int strIU7ng_replace_test6()
{
    strIU7ng str = strIU7ng_create("bbbb");
    strIU7ng search = strIU7ng_create("bb");
    strIU7ng replace = strIU7ng_create("");
    strIU7ng expected = strIU7ng_create("");

    strIU7ng result = strIU7ng_replace(str, search, replace);

    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int strIU7ng_replace_test7()
{
    strIU7ng str = strIU7ng_create("bbbb");
    strIU7ng search = strIU7ng_create("");
    strIU7ng replace = strIU7ng_create("aaa");
    strIU7ng expected = strIU7ng_create("");

    strIU7ng result = strIU7ng_replace(str, search, replace);

    int error = 1;

    if (!strIU7ng_cmp(expected, str))
        error = 0;

    strIU7ng_free(&str);
    strIU7ng_free(&search);
    strIU7ng_free(&replace);
    strIU7ng_free(&expected);
    strIU7ng_free(&result);

    if (error == 1)
    {
        printf("Str replace test failed!\n");
        printf("Expected string is %s\n", expected.head);
        printf("Result string is %s\n", result.head);
    }
    
    return error;
}

int main(void)
{
    int errorcount = 0;

    errorcount += strIU7ng_replace_test1();
    errorcount += strIU7ng_replace_test2();
    errorcount += strIU7ng_replace_test3();
    errorcount += strIU7ng_replace_test4();
    errorcount += strIU7ng_replace_test5();
    errorcount += strIU7ng_replace_test6();
    errorcount += strIU7ng_replace_test7();                        
    
    printf("%d of 7 tests passed successfully.\n", errorcount);
    
    return 0;
}
