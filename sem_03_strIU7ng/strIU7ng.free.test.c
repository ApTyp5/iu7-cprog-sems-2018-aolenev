
#include <stdio.h>

#include "strIU7ng.h"

int free_test(strIU7ng str)
{
    strIU7ng_free(str);

    return (str.len == 0 && str.head == NULL);
}

int main()
{
    strIU7ng str = strIU7ng_create("HELLO");
    int success = 0;

    success += free_test(str);

    printf("%d", success);
    return 0;
}
