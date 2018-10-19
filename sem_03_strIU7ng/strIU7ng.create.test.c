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

int test_empty_string(int *clear_tests)
{
    char *str_input = "";
    strIU7ng str_output;
    
    str_output = strIU7ng_create(str_input);
    
    if ((str_output.len != 0) || (str_output.head[0] != 0))
        return ERR_DEFAULT;
    
    *clear_tests = *clear_tests + 1;
    
    return SUCCESS;
}

int test_not_existing_string(int *clear_tests)
{
    char *str_input = NULL;
    strIU7ng str_output;
    
    str_output = strIU7ng_create(str_input);
    
    if (str_output.head != NULL)
        return ERR_DEFAULT;
        
    *clear_tests = *clear_tests + 1;
    
    return SUCCESS;  
}

int test_normal(int *clear_tests)
{
    char *str_input = "Hello, World!";
    strIU7ng str_output;
    int i;
    
    str_output = strIU7ng_create(str_input);
    
    if (str_output.len != 13)
        return ERR_DEFAULT;
        
    for (i = 0; i < 13; i++)
    {
        if (str_input[i] != str_output.head[i])
            return ERR_DEFAULT;
    }
    
    *clear_tests = *clear_tests + 1;
    
    return SUCCESS; 
}

int main(void)
{
    int clear_tests = 0;
    
    test_empty_string(&clear_tests);
    test_not_existing_string(&clear_tests);
    test_normal(&clear_tests);
    
    printf("Passed %d out of 3 tests", clear_tests);
    
    if (clear_tests == 3)
        return SUCCESS;
        
    return ERR_DEFAULT;
}
