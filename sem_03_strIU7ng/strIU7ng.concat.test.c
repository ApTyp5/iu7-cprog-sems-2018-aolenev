#include "strIU7ng.h"
#include <string.h>

void strIU7ng_concat_test_1(int *success)
{
    strIU7ng str1 = strIU7ng_create("M&M");
    strIU7ng str2 = strIU7ng_create(" rules");

    strIU7ng str_res = strIU7ng_concat(str1, str2);
	
    if (str1.len + str2.len == str_res.len &&
	    strcmp(str_res.head, "M&M rules") == 0)
    	(*success)++;	
}

void strIU7ng_concat_test_2(int *success)
{
    strIU7ng str1 = strIU7ng_create("M&M");
    strIU7ng str2 = strIU7ng_create("");

    strIU7ng str_res = strIU7ng_concat(str1, str2);
	
    if (str1.len + str2.len == str_res.len &&
	    strcmp(str_res.head, "M&M") == 0)
    	(*success)++;	
}

int main(void)
{
    int success = 0;
    int musttests = 2;

    strIU7ng_concat_test_1(&success);
    strIU7ng_concat_test_2(&success);
	
    printf("\n Function concat works at %d of %d tests\n", success, musttests);

    return 0;
}
