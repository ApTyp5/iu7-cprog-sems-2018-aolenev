#include "liu7st.h"

int main()
{
    liu7st list = liu7st_create();
    
    if (NULL == list.first && NULL == list.last && 0 == list.size)
    {
	printf("SUCCESS");
	return SUCCESS;
    }

    printf("FAILED");
    return FAILED;
} 
