#include "strIU7ng.h"

int str_find_test()
{
    int errorcount= 0;

    /*
      test1
    */

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
    
    result = find_substrIU7ng(test_string_a1, test_string_b1);

    if (expected != result)
    {
        printf("Error testing find_substrIU7ng!\n");
        printf("String 1 is %.*s\n", test_string_a1.len, test_string_a1.head);
        printf("Substr 1 is %.*s\n", test_string_b1.len, test_string_b1.head);
        printf("Pointer 1 offset is %ld\n", result - test_string_a1.head);
        printf("%s\n", result);
        printf("Result and expected pointer do not match\n");
        errorcount += 1;
    }

    /*
      test2
    */
    
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
    
    result2 = find_substrIU7ng(test_string_a2, test_string_b2);

    if (expected2 != result2)
    {
        printf("Error testing find_substrIU7ng!\n");
        printf("String 2 is %.*s\n", test_string_a2.len, test_string_a2.head);
        printf("Substr 2 is %.*s\n", test_string_b2.len, test_string_b2.head);
        printf("Result and expected pointer do not match\n");
        errorcount += 1;
    }
    
    /*
      test3
    */

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
    
    result3 = find_substrIU7ng(test_string_a3, test_string_b3);

    if (expected3 != result3)
    {
        printf("Error testing find_substrIU7ng!\n");
        printf("String 3 is %.*s\n", test_string_a3.len, test_string_a3.head);
        printf("Substr 3 is %.*s\n", test_string_b3.len, test_string_b3.head);
        printf("Result and expected pointer do not match\n");
        errorcount += 1;
    }
    
    return errorcount;
}

/*
  str_find test
*/

int main()
{
    int errorcount = 0;
    printf("Testing find_substrIU7ng()\n");
    
    errorcount += str_find_test(); 
    if (errorcount != SUCCESS)
    {
        printf("Test find_substrIU7ng() failed\n");
        return errorcount;
    }

    return SUCCESS;
}
