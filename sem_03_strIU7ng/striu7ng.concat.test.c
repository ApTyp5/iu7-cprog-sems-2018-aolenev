#include "striu7ng.h"

int main(void)
{
    float Success = 0;
    int musttests = 4;
    printf("\n");

    striu7ng str1 = striu7ng_create("M&M");
    striu7ng str2 = striu7ng_create(" rules");
    striu7ng str3 = striu7ng_create("");


    striu7ng str_res = striu7ng_concat(str1, str2);
    if (str1.len + str2.len == str_res.len)
    	Success++;
    if (strcmp(str_res.head, "M&M rules") == 0)
    	Success++;

    str_res = striu7ng_concat(str1, str3);
    if (str3.len + str1.len == str_res.len)
    	Success++;
    if (strcmp(str_res.head, "M&M") == 0)
    	Success++;

    float result = Success / musttests * 100;
    printf("\n Function concat works at %.2f percents \n", result);
	
    return 0;
}