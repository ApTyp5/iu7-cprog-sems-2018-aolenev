
#include <string.h>
#include "strIU7ng.h"

#define         HAPPY_END           0 
#define         NON_HAPPY_END       -1 

int main()
{
    strIU7ng str = strIU7ng_create("D & P");
    
    int len;
    int exp_len = 3;

    strIU7ng *arr = strIU7ng_split(str, ' ', &len);

    result = len == exp_len ? HAPPY_END : NON_HAPPY_END;
    result = strcmp(arr[1], "&"));

    printf("Split test : %s\n", result ? "CRACH" : "SUCCESS");

    return 0;
}


        
    

    
