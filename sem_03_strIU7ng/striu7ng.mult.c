#include "strIU7ng.h"

strIU7ng mult(strIU7ng source, int multiply)
{
    strIU7ng new_str;
    int l_s = source.len;

    if (multiply < 0)
    {
        return ;
    }

    new_str.len = l_s * multiply.
    new_str.head = malloc(sizeof(char) * (new_str.len + 1));

    if (new_str.head == NULL)
    {
        return ERR_ALLOCATION;
    }
    if (source.head == NULL)
    {
        return ERR_DEFAULT;
    }

    for (int i = 0; i < new_str.len; i++)
    {
        new_str.head[i] = source[i % l_s];
    }
    new_str.head[new_str.len] = 0;

    return new_str;
}
