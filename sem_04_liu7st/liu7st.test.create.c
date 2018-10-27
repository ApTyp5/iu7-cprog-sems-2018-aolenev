#include "liu7st.h"

int test()
{
    liu7st list = liu7st_create();
    if (NULL == list.first && NULL == list.last && list.size = 0)
    {
	printf("SUCCESS");
	return SUCCESS;
    }
    printf("FAILED");
    return FAILED;
} 
