#include <stdlib.h>

#include "strIU7ng.h"

int byte_replace(strIU7ng str, char what, char on_what)
{   
    int n = 0;
    for (int i = 0; i < strIU7ng_len(str); i++)
        if (str.head[i] == what)
        {
            n++;
            str.head[i] = on_what;
        }

    return n;
}


strIU7ng* split(strIU7ng string, char delimiter, int *new_size)
{
    int n = byte_replace(string, delimiter, 0);

    strIU7ng *array = malloc(sizeof(strIU7ng) * n);
    if (array == NULL)
    {
        *new_size = 0;
        return NULL;
    }

    char *beg = string.head;

    for (int i = 0; i < n; i++)
    {
        array[i] = strIU7ng_create(beg);
        beg += strIU7ng_len(array[i]) + 1;
    }

    byte_replace(string, 0, delimiter);

    *new_size = n;
    return array;

}
