#include <stdio.h>

#include "triu7.h"

void test_no_cycle_0(int *passed)
{
    int expected = IU7_FALSE;
    triu7_ptr root;
    
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    triu7_add(root->leavs->first->data, &fake_data, 1);
    triu7_add(root->leavs->first->data, &fake_data, 1);
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("No cycle test #1:     not passed.\n");
    }
    else
    {
        printf("No cycle test #1:     passed.\n");
        *passed = *passed + 1;
    }
}

void test_no_cycle_1(int *passed)
{
    int expected = IU7_FALSE;
    triu7_ptr root;
    
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("No cycle test #2:     not passed.\n");
    }
    else
    {
        printf("No cycle test #2:     passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_0(int *passed)
{
    int expected = IU7_TRUE;
    triu7_ptr root;
    
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    
    root->leavs->first->data = root;
    
    if(triu7_has_cycle(root) != expected)
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
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr cycle_node;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    cycle_node = root->leavs->first->data;
    
    cycle_node->leavs->first->data = root;
    
    if(triu7_has_cycle(root) != expected)
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
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr cycle_node;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    cycle_node = root->leavs->first->data;
    
    cycle_node->leavs->first->data = root->leavs->last->data;
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("Cycle test #3:        not passed.\n");
    }
    else
    {
        printf("Cycle test #3:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_3(int *passed)
{
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr node;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    node = root->leavs->first->data;
    
    triu7_add(node, &fake_data, 1);
    triu7_add(node, &fake_data, 1);
    
    triu7_add(root, &fake_data, 1);
    
    root->leavs->last->data = node->leavs->first->data;
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("Cycle test #4:        not passed.\n");
    }
    else
    {
        printf("Cycle test #4:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_4(int *passed)
{
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr node;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    node = root->leavs->first->data;
    
    triu7_add(node, &fake_data, 1);
    triu7_add(node, &fake_data, 1);
    
    node->leavs->first->data = root;
    
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("Cycle test #5:        not passed.\n");
    }
    else
    {
        printf("Cycle test #5:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_5(int *passed)
{
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr cycle_node;
    triu7_ptr node;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    node = root->leavs->first->data;
    
    triu7_add(node, &fake_data, 1);
    triu7_add(node, &fake_data, 1);
    
    node->leavs->first->data = root->leavs->last->data;
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("Cycle test #6:        not passed.\n");
    }
    else
    {
        printf("Cycle test #6:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_6(int *passed)
{
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr cycle_node;
    triu7_ptr node;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    node = root->leavs->first->data;
    
    triu7_add(node, &fake_data, 1);
    triu7_add(node, &fake_data, 1);
    
    root->leavs->last->data = node->leavs->first->data;
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("Cycle test #7:        not passed.\n");
    }
    else
    {
        printf("Cycle test #7:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_cycle_7(int *passed)
{
    int expected = IU7_TRUE;
    triu7_ptr root;
    triu7_ptr node;
    triu7_ptr node_b;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);
    
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    triu7_add(root, &fake_data, 1);
    
    node = root->leavs->first->data;
    
    triu7_add(node, &fake_data, 1);
    triu7_add(node, &fake_data, 1);
    
    node_b = root->leavs->first->data;
    
    triu7_add(node_b, &fake_data, 1);
    triu7_add(node_b, &fake_data, 1);
    
    node->leavs->last->data = node_b->leavs->first->data;
    
    if(triu7_has_cycle(root) != expected)
    {
        printf("Cycle test #8:        not passed.\n");
    }
    else
    {
        printf("Cycle test #8:        passed.\n");
        *passed = *passed + 1;
    }
}

void test_invalid_0(int *passed)
{
    int expected = IU7_FALSE;
    triu7_ptr root;
    char fake_data = 0;
    
    root = NULL;
    
    if(triu7_has_cycle(root) != expected)
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
    int expected = IU7_FALSE;
    triu7_ptr root;
    char fake_data = 0;
    
    root = triu7_create(&fake_data);

    triu7_add(root, &fake_data, 1);
    
    root->leavs->first->data = NULL;
    
    if(triu7_has_cycle(root) != expected)
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
    
    test_no_cycle_0(&passed);
    test_no_cycle_1(&passed);
    test_cycle_0(&passed);
    test_cycle_1(&passed);
    test_cycle_2(&passed);
    test_cycle_3(&passed);
    test_cycle_4(&passed);
    test_cycle_5(&passed);
    test_cycle_6(&passed);
    test_cycle_7(&passed);
    test_invalid_0(&passed);
    test_invalid_1(&passed);
    
    if(passed == 6)
    {
        printf("All tests successfuly passed!\n");
        return IU7_SUCCESS;
    }
    else
    {
        printf("Not all tests passed!\n");
        return IU7_FAIL;
    }
}
