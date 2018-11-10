#include <stdio.h>

#include "triu7.h"

void test_no_cycle(int *passed)
{
    int expected = FALSE;
    triu7 tree;
    
    if(triu7_has_cycle(tree) != expected)
    {
        printf("No cycle test:        not passed.\n");
    }
    else
    {
        printf("No cycle test:        passed.\n")
        *passed = *passed + 1;
    }
}

void test_cycle_0(int *passed)
{
    int expected = TRUE;
    triu7 tree;
    
    if(triu7_has_cycle(tree) != expected)
    {
        printf("Cycle test #1:        not passed.\n");
    }
    else
    {
        printf("Cycle test #1:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_1(int *passed)
{
    int expected = TRUE;
    triu7 tree;
    
    if(triu7_has_cycle(tree) != expected)
    {
        printf("Cycle test #2:        not passed.\n");
    }
    else
    {
        printf("Cycle test #2:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_2(int *passed)
{
    int expected = TRUE;
    triu7 tree;
    
    if(triu7_has_cycle(tree) != expected)
    {
        printf("Cycle test #3:        not passed.\n");
    }
    else
    {
        printf("Cycle test #3:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_invalid_0(int *passed)
{
    int expected = FALSE;
    triu7 tree;
    
    if(triu7_has_cycle(tree) != expected)
    {
        printf("Invalid tree test #1: not passed.\n");
    }
    else
    {
        printf("Invalid tree test #1: passed.\n");
        *passed = *passed + 1;
    }
}

void test_invalid_1(int *passed)
{
    int expected = FALSE;
    triu7 tree;
    
    if(triu7_has_cycle(tree) != expected)
    {
        printf("Invalid tree test #2: not passed.\n");
    }
    else
    {
        printf("Invalid tree test #2: passed.\n");
        *passed = *passed + 1;
    }
}

int main()
{
    int passed = 0;
    
    test_no_cycle(&passed);
    test_cycle_0(&passed);
    test_cycle_1(&passed);
    test_cycle_2(&passed);
    test_invalid_0(&passed);
    test_invalid_1(&passed);
    
    if(passed == 6)
    {
        printf("All tests successfuly passed!\n");
        return SUCCESS;
    }
    else
    {
        printf("Not all tests passed!\n");
        return FAIL;
    }
}
