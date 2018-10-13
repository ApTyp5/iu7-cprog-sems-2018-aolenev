#include "strIU7ng.h"

strIU7ng mult(strIU7ng source, int multiply)
{
    strIU7ng new_str;
    int l_s = source.len;

    new_str.len = l_s * multiply.
    new_str.head = malloc(sizeof(char) * l_s * multiply);


    for (int i = 0; i < multiply * l_s; i++)
    {
        new_str.head[i] = source[l_s % i];
    }

    return new_str;
}
