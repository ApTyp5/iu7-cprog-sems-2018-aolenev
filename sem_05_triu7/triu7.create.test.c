#include "triu7.h"
#include <stdio.h>

int main()
{
    printf("Create test started:\n");

    int x = 5;
    void *data = &x;
    triu7_ptr tree = triu7_create(data);
    
    if (tree->data == data && tree->leavs->size == 0 && tree->leavs == NULL)
    {
        printf("test passed\n");
    }
    else
    {
        printf("test not passed\n");
    }

    return 0;
}

