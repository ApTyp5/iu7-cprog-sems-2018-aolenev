#include "strIU7ng.h"

int main(void)
{
    float Success = 0;
    int musttests = 4;
    printf("\n");

    strIU7ng str1 = strIU7ng_create("M&M");
    strIU7ng str2 = strIU7ng_create(" rules");
    strIU7ng str3 = strIU7ng_create("");


    strIU7ng str_res = strIU7ng_concat(str1, str2);
    if (str1.len + str2.len == str_res.len)
    	Success++;
    if (strcmp(str_res.head, "M&M rules") == 0)
    	Success++;

    str_res = strIU7ng_concat(str1, str3);
    if (str3.len + str1.len == str_res.len)
    	Success++;
    if (strcmp(str_res.head, "M&M") == 0)
    	Success++;

    float result = Success / musttests * 100;
    printf("\n Function concat works at %.2f percents \n", result);
	
    return 0;
}