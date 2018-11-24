#include <stdio.h>

#include "triu7.h"
void test_depth_0(int *passed)
{
    int expected = 1;
    triu7_ptr root;
    
    root = triu7_create(NULL);
    
    if(triu7_depth(root) != expected)
    {
        printf("Depth test #1:        not passed.\n");
    }
    else
    {
        printf("Depth test #1:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_depth_1(int *passed)
{
    int expected = 2;
    triu7_ptr root;
    
    root = triu7_create(NULL);
    triu7_add(root, NULL, 1);
    if(triu7_depth(root) != expected)
    {
        printf("Depth test #2:        not passed.\n");
    }
    else
    {
        printf("Depth test #2:        passed.\n");
        *passed = *passed + 1;
    }
}

int main()
{
    int passed = 0;
    
    test_depth_0(&passed);
    test_depth_1(&passed);

    
    if(passed == 2)
    {
        printf("All tests successfuly passed!\n");
        return IU7_SUCCESS;
    }
    else
    {
        printf("Not all tests passed!\n");
        return IU7_SUCCESS;
    }
}
