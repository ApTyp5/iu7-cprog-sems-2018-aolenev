
#include <stdio.h>

#include "strIU7ng.h"

int free_test(strIU7ng str)
{
    strIU7ng_free(&str);

    return (str.len == 0 && str.head == NULL);
}

int main()
{
    strIU7ng str;
    int success = 0;
    char *st = malloc(128);

    for (int i = 0; i < 10; i++)
        st[i] = 'a';
    st[10] = '\0';
    str.head = st;
    str.len = 10;
    success += free_test(str);

    printf("%d", success);
    return 0;
}
