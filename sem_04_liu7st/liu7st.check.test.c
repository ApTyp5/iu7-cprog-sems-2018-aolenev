#include "liu7st.h"

#define TEST(CONDITION) \
printf("Test %d (" #CONDITION "): %s\n", ++tests_total, CONDITION ? ++tests_passed, "passed" : "failed")

int tests_total = 0, tests_passed = 0;

void print_tests_summary()
{
    printf("Passed %d tests from %d total.\n", tests_passed, tests_total);
}

void test_normal()
{
    liu7st list = liu7st_create();
    int a = 10, b = 20, c = 30;

    liu7st_append(&list, &a);
    liu7st_append(&list, &b);
    liu7st_append(&list, &c);

    TEST(!liu7st_check(list));
}

void test_cycled()
{
    liu7st list = liu7st_create();
    int a = 10, b = 20, c = 30;

    liu7st_append(&list, &a);
    liu7st_append(&list, &b);
    liu7st_append(&list, &c);

    list.last->next = list.first->next;

    TEST((liu7st_check(list) & LIU7ST_CYCLED));
}

void test_back_cycled()
{
    liu7st list = liu7st_create();
    int a = 10, b = 20, c = 30;

    liu7st_append(&list, &a);
    liu7st_append(&list, &b);
    liu7st_append(&list, &c);

    list.first->prev = list.first->next;

    TEST((liu7st_check(list) & LIU7ST_BACK_CYCLED));
}

void test_nonlinear()
{
    liu7st list = liu7st_create();
    int a = 10, b = 20, c = 30;

    liu7st_append(&list, &a);
    liu7st_append(&list, &b);
    liu7st_append(&list, &c);

    liu7st_element *elem = malloc(sizeof(liu7st_element));

    list.last->prev = elem;

    TEST((liu7st_check(list) & LIU7ST_NONLINEAR));
}

int main()
{
    test_normal();
    test_cycled();
    test_back_cycled();
    test_nonlinear();

    print_tests_summary();
    return tests_total != tests_passed;
}
