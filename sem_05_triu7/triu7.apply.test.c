#include <stdio.h>
#include <stdlib.h>
#include "colours.h"

#include "triu7.h"

#define TEST(CONDITION) \
    printf("Test %d (" #CONDITION "): %s\n", ++tests_total, CONDITION ? ++tests_passed, "passed" : "failed")

int tests_total = 0, tests_passed = 0;

void print_tests_summary()
{
    printf("Passed %d tests from %d total.\n", tests_passed, tests_total);
    printf("Verdict: %s%s%s\n", tests_passed == tests_total ? GREEN : RED,
                       tests_passed == tests_total ? "SUCCESS" : "FAIL", END_C);
}

void do_nothing(void *data)
{
}

void mult_by_2(void *data)
{
    *(int*)data = *(int*)data * 2;
}

void test_func_nullptr()
{
    int a = 10;
    triu7_ptr tree = triu7_create(&a);
    TEST(triu7_apply(tree, NULL));
}

void test_tree_nullptr()
{
    TEST(triu7_apply(NULL, do_nothing));
}

void test_both_nullptr()
{
    TEST(triu7_apply(NULL, NULL));
}

void test_without_modify()
{
    int a = 10, b = 20, c = 30;
    triu7_ptr tree = triu7_create(&a);
    triu7_add(tree, &b, 1);
    triu7_add(tree, &c, 1);

    triu7_apply(tree, do_nothing);
    TEST(tree->data == &a && a == 10
        && tree->leavs->size == 2
        && ((triu7_ptr)liu7st_get(*tree->leavs, 0))->data == &b && b == 20
        && ((triu7_ptr)liu7st_get(*tree->leavs, 1))->data == &c && c == 30);
}

void test_with_modify()
{
    int a = 10, b = 20, c = 30;
    triu7_ptr tree = triu7_create(&a);
    triu7_add(tree, &b, 1);
    triu7_add(tree, &c, 1);

    triu7_apply(tree, mult_by_2);
    TEST(tree->data == &a && a == 20
        && tree->leavs->size == 2
        && ((triu7_ptr)liu7st_get(*tree->leavs, 0))->data == &b && b == 40
        && ((triu7_ptr)liu7st_get(*tree->leavs, 1))->data == &c && c == 60);
}

int main()
{
    test_tree_nullptr();
    test_func_nullptr();
    test_both_nullptr();
    test_without_modify();
    test_with_modify();

    print_tests_summary();
    return tests_total != tests_passed;
}
