#include <stdio.h>
#include <stdlib.h>

#include "strIU7ng.h"

strIU7ng strIU7ng_create(char *str)
{
    strIU7ng result_string;
    int i;
    int len = 0;
    
    if (str == NULL)
    {
        result_string.head = NULL;
        return result_string;
    }
    
    if (str[0] == 0)
    {
        result_string.len = 0;
        result_string.head = malloc(sizeof(char));
        if (!(result_string.head))
        {
            result_string.head = NULL;
            return result_string;
        }
        result_string.head[0] = 0;
        return result_string;
    }
    
    
    for (i = 0; str[i] != '\0'; i++)
        len = len + 1;
        
    result_string.len = len;
    
    result_string.head = malloc(sizeof(char) * len);
    
    if (!(result_string.head))
    {
        result_string.head = NULL;
        return result_string;
    }
    
    for (i = 0; i < len; i++)
        result_string.head[i] = str[i];
    
    return result_string;
}
