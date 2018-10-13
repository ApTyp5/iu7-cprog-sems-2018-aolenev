#include <stdlib.h>

#include "strIU7ng.h"

strIU7ng* split(strIU7ng string, char delimiter, int *new_size)
{
    int n = 0;
    for (int i = 0; i < strIU7ng_len(string); i++)
    {
        if (string.head[i] == delimiter)
        {
            n++;
            string.head[i] = '\0';
        }
    }

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

    for (int i = 0; i < strIU7ng_len(string); i++)
        if (string.head[i] == '\0')
            string.head[i] = delimiter;

    *new_size = n;
    return array;

}
