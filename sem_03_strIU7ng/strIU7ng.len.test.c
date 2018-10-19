#include "strIU7ng.h"

int test_strIU7ng_len1()
{
    printf("strIU7ng_len test1 : positive test\n");
    strIU7ng test1;
    char test_str1[10] = "123456789";
    test1.len = 9;
    test1.head = test_str1;

    int result = strIU7ng_len(test1);
    
    if (result != 9)
    {
	printf("test failed! expected len %d result is %d", test1.len, result);
	return 1;
    }

    return 0;
}

int test_strIU7ng_len2()
{
    printf("strIU7ng_len test2 : string head is NULL\n");
    strIU7ng test2;
    test2.len = 9000;
    test2.head = NULL;

    int result = strIU7ng_len(test2);

    if (result != ERR_DEFAULT)
    {
	printf("test failed! expected return value to be ERR_DEFAULT\n");
	printf("result is %d\n", result);
	return 1;
    }
    
    return 0;
}

int test_strIU7ng_len3()
{
    printf("strIU7ng_len test3 : string len is negative\n");
    strIU7ng test3;
    char test_str3[4] = "hey";
    test3.len = -2134;
    test3.head = test_str3;

    int result = strIU7ng_len(test3);

    if (result != ERR_DEFAULT)
    {
	printf("test failed! expected the return value to be ERR_DEFAULT\n");
	printf("result is %d\n", result);
	return 1;
    }

    return 0;
}

int main()
{
    int errorcount = 0;

    printf("testing strIU7ng_len()\n");

    errorcount += test_strIU7ng_len1();
    errorcount += test_strIU7ng_len2();
    errorcount += test_strIU7ng_len3();

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
