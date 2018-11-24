#include <stdio.h>
#include <stdlib.h>

#include "triu7.h"

#define TEST(CONDITION) \
    printf("Test %d (" #CONDITION "): %s\n", ++tests_total, CONDITION ? ++tests_passed, "passed" : "failed")

int tests_total = 0, tests_passed = 0;

void print_tests_summary()
{
    printf("Passed %d tests from %d total.\n", tests_passed, tests_total);
}

void test_tree_nullptr()
{
    int a = 10;
    TEST(triu7_add(NULL, &a, 1));
}

void test_data_nullptr()
{
    int a = 10;
    triu7_ptr tree = triu7_create(&a);
    TEST(triu7_add(tree, NULL, 1));
}

void test_both_nullptr()
{
    TEST(triu7_add(NULL, NULL, 1));
}

void test_normal()
{
    int a = 10, b = 20;
    triu7_ptr tree = triu7_create(&a);
    TEST(!triu7_add(tree, &b, 1)
        && tree->leavs->size == 1 
        && ((triu7_ptr)liu7st_get(*tree->leavs, 0))->data == &b);
}

int main()
{
    test_tree_nullptr();
    test_data_nullptr();
    test_both_nullptr();
    test_normal();

    print_tests_summary();
    return tests_total != tests_passed;
}
