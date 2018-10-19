#include "strIU7ng.h"

int test_strIU7ng_len()
{
    int errorcount = 0;

    strIU7ng test1;
    char test_str1[10] = "123456789";
    test1.len = 9;
    test1.head = test_str1;

    if (strIU7ng_len(test1) != 9)
        errorcount += 1;

    strIU7ng test2;
    test2.len = 9000;
    test2.head = NULL;

    if (strIU7ng_len(test2) != ERR_DEFAULT)
        errorcount += 1;

    strIU7ng test3;
    char test_str3[4] = "hey";
    test3.len = -2134;
    test3.head = test_str3;

    if (strIU7ng_len(test3) != ERR_DEFAULT)
        errorcount += 1;

    return errorcount;
}

int main()
{
    int errorcount = 0;

    if (errorcount == 0)
    {
        return 0;
    }
    else
    {
        printf("strIU7ng_len() test error!");
        return errorcount;
    }
}
