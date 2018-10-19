#include "strIU7ng.h"

int test_strIU7ng_len()
{
    int errorcount = 0;

    strIU7ng test1;
    char test_str1[10] = "123456789";
    test1.len = 9;
    test1.head = test_str1;

    if (strIU7ng(test1) != 9)
        errorcount += 1;

    strIU7ng test2;
    test.len = 9000;
    test.head = NULL;

    if (strIU7ng(test2) != ERR_DEFAULT)
        errorcount += 1;

    strIU7ng test3;
    char test_str3[4] = "hey";
    test.len = -2134;
    test.head = test_str3;

    if (strIU7ng(test3) != ERR_DEFAULT)
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
