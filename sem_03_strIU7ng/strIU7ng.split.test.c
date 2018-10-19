#include <stdlib.h>
#include <string.h>
#include "strIU7ng.h"

#define         HAPPY_END           0 
#define         NON_HAPPY_END       -1 

int strIU7ng_cmp(strIU7ng s1, strIU7ng s2)
{
    int i;
    for (i = 0; i < s1.len && i < s2.len && s1.head[i] == s2.head[i]; i++);
    return (i == s1.len ? '\0' : s1.head[i]) - (i == s2.len ? '\0' : s2.head[i]);
}

int main()
{
    strIU7ng str = strIU7ng_create("D & P");
    
    int len;
    int exp_len = 3;
    strIU7ng exp_str = strIU7ng_create("&");

    strIU7ng *arr = strIU7ng_split(str, ' ', &len);

    int result = (len == exp_len && !strIU7ng_cmp(arr[1], exp_str)) ? HAPPY_END : NON_HAPPY_END;

    printf("Split test : %s\n", result ? "CRASH" : "SUCCESS");

    free(arr);
    strIU7ng_free(&str);
    strIU7ng_free(&exp_str);

    return 0;
}


        
    

    
