#include "strIU7ng.h"

int str_find_test1()
{
    /*
      test1
    */
    printf("strIU7ng_find_substr positive test 1\n");
    int error = 0;

    strIU7ng test_string_a1;
    char test_head1[20] = "test data 1 is here";
    test_string_a1.head = test_head1;
    test_string_a1.len = 19;

    strIU7ng test_string_b1;
    char test_head2[5] = "data";
    test_string_b1.head = test_head2;
    test_string_b1.len = 4;

    char * expected = test_string_a1.head + 5;
    
    char * result;
    
    result = strIU7ng_find_substr(test_string_a1, test_string_b1);

    if (expected != result)
    {
        printf("Error testing strIU7ng_find_substr!\n");
        printf("String 1 is %.*s\n", test_string_a1.len, test_string_a1.head);
        printf("Substr 1 is %.*s\n", test_string_b1.len, test_string_b1.head);
        printf("Pointer 1 offset is %ld\n", result - test_string_a1.head);
        printf("%s\n", result);
        printf("Result and expected pointer do not match\n");
	error = 1;
    }

    return error;
}

int str_find_test2()
{    
    /*
      test2
    */
    printf("strIU7ng_find_substr test 2: substr is not present\n");
    int error = 0;
    
    strIU7ng test_string_a2;
    char test_head_a2[20] = "test data 2 is here";
    test_string_a2.head = test_head_a2;
    test_string_a2.len = 20;

    strIU7ng test_string_b2;
    char test_head_b2[5] = "bird";
    test_string_b2.head = test_head_b2;
    test_string_b2.len = 5;

    char * const expected2 = NULL;
    
    char * result2;
    
    result2 = strIU7ng_find_substr(test_string_a2, test_string_b2);

    if (expected2 != result2)
    {
        printf("Error testing strIU7ng_find_substr!\n");
        printf("String 2 is %.*s\n", test_string_a2.len, test_string_a2.head);
        printf("Substr 2 is %.*s\n", test_string_b2.len, test_string_b2.head);
        printf("Result and expected pointer do not match\n");
	printf("resulting pointer is not NULL and is %p\n", result2);
	error = 1;
    }

    return error;
}

int str_find_test3()
{
    /*
      test3
    */
    printf("strIU7ng_find_substr test 3: substr is too big\n");
    int error = 0;

    strIU7ng test_string_a3;
    char test_head_a3[20] = "test data 3 is here";
    test_string_a3.head = test_head_a3;
    test_string_a3.len = 20;

    strIU7ng test_string_b3;
    char test_head_b3[36] = "sometimes the string is just too big";
    test_string_b3.head = test_head_b3;
    test_string_b3.len = 36;

    char * const expected3 = NULL;
    
    char * result3;
    
    result3 = strIU7ng_find_substr(test_string_a3, test_string_b3);

    if (expected3 != result3)
    {
        printf("Error testing strIU7ng_find_substr!\n");
        printf("String 3 is %.*s\n", test_string_a3.len, test_string_a3.head);
        printf("Substr 3 is %.*s\n", test_string_b3.len, test_string_b3.head);
        printf("Result and expected pointer do not match\n");
	printf("Resulting pointer is not NULL and is %p\n", result3);
	error = 1;
    }

    return error;
}    

int str_find_test4()
{
    /*
      test4
    */
    printf("strIU7ng_find_substr test 4: substr clips at the end of string\n");
    int error = 0;
    
    strIU7ng test_string_a4;
    char test_head_a4[20] = "test data 4 is here";
    test_string_a4.head = test_head_a4;
    test_string_a4.len = 20;

    strIU7ng test_string_b4;
    char test_head_b4[46] = "sometimes the string is just too big";
    test_string_b4.head = test_head_b4;
    test_string_b4.len = 36;

    char * const expected4 = NULL;
    
    char * result4;
    
    result4 = strIU7ng_find_substr(test_string_a4, test_string_b4);

    if (expected4 != result4)
    {
        printf("Error testing strIU7ng_find_substr!\n");
        printf("String 4 is %.*s\n", test_string_a4.len, test_string_a4.head);
        printf("Substr 4 is %.*s\n", test_string_b4.len, test_string_b4.head);
        printf("Result and expected pointer do not match\n");
	printf("Resulting pointer is not NULL and is %p\n", result4);
	error = 1;
    }

    return error;
}    

/*
  str_find test
*/
int main()
{
    int errorcount = 0;
    printf("Testing strIU7ng_find_substr()\n");
    
    errorcount += str_find_test1();
    errorcount += str_find_test2();
    errorcount += str_find_test3();
    errorcount += str_find_test4();
    
    if (errorcount != SUCCESS)
    {
        printf("Test strIU7ng_find_substr() failed\n");
        return errorcount;
    }

    return SUCCESS;
}
