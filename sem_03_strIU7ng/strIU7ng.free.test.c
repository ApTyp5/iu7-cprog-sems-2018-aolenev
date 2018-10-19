#include <stdio.h>

#include "strIU7ng.h"

int free_test(strIU7ng str, int *count)
{
    strIU7ng_free(&str);
    *count += 1;
    
    return (str.len == 0 && str.head == NULL);
}

int main()
{
    strIU7ng str;
    int success = 0, count = 0;
    char *st = malloc(128);

    for (int i = 0; i < 10; i++)
        st[i] = 'a';
    st[10] = '\0';
    str.head = st;
    str.len = 10;
    success += free_test(str, &count);
    printf("\nFree func test:\n");
    
    if (success == count)
        printf("Test passed.\nPassed tests: %d/%d\n", success, count);
    else
        printf("Test failed.\nPassed tests: %d/%d\n", success, count);
    
    return 0;
}
