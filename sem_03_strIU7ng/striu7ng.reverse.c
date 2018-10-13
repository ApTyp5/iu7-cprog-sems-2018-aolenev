#include "striu7ng.h"

strIU7ng reverse(strIU7ng string)
{
    char *result = malloc(string.len);

    if (result == NULL)
        return NULL;

    for (int i = 0; i < string.len; i++)
        result[i] = string.head[string.len - i];
    
    return strIU7ng_create(result);    
}
