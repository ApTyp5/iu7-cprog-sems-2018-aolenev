#inclide "striu7ng.h"

striu7ng striu7ng_concat(striu7ng str1, striu7ng str2)
{
    int n = str1.len + str2.len;
    char str3[n + 1];
    
    for (int i = 0; i < str1.len; i++)
        str3[i] = str1[i];
    
    for (int i = 0; i < str2.len; i++)
        str3[str1 + i] = str2[i];
    
    str3[n] = '\0';
    
    return striu7ng_create(str3);
}   