#include <stdio.h>
#include <stdlib.h>

#include "strIU7ng.h"

strIU7ng strIU7ng_create(char *str)
{
    strIU7ng result_string;
    int i;
    int len = 0;
    
    for (i = 0; str[i] != '\0'; i++)
        len = len + 1;
        
    result_string.len = len;
    
    result_string.head = malloc(sizeof(char) * len);
    
    for (i = 0; i < len; i++)
        result_string.head[i] = str[i];
    
    return result_string;
}
