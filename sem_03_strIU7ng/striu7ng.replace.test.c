#include <stdio.h>
#include <STRIU7NG.h>

void test_replace_ordinary(void)
{
    strIU7ng source = strIU7ng_create("Piter Parker"), search = strIU7ng_create("P"), replace = strIU7ng("B");
    strIU7ng result1 = strIU7ng_replace(source, search, replace), result2 = strIU7ng_create("Biter Barker");
    if (result1.len == result2.len)
    {
	for (int i = 0;result1.head[i] == result2.head[i] ;i++)
	    if (result1.head[i] == '\0')
		printf("Test test_replace_ordinary success.\n");
    }
    else
	printf("Test test_replace_ordinary is failed.\n");
}
    
}

int  main(void)
{
    test_replace_ordinary(); 
    
    return 0;
}
