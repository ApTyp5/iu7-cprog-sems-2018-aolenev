#include "triu7.h"
#include <stdio.h>

void major_test();

int main()
{
    major_test();

    return 0;
}



void major_test()
{
    printf("Create test started:\n");

    int x = 5;
    void *data = &x;
    triu7_ptr tree = triu7_create(data);
    
    if (tree->data == data && 
        tree->leavs->size == 0)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST NOT PASSED\n");
        printf("tree->data == data: %d\n", tree->data == data);
        printf("tree->leavs->size == 0: %d\n", tree->leavs->size == 0);
    }
}

