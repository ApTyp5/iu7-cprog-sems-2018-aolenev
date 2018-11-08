#include "liu7st.h"

#define TEST(CONDITION) \
    printf("Test %d (" #CONDITION "): %s\n", ++tests_total, CONDITION ? ++tests_passed, "passed" : "failed")

int tests_total = 0, tests_passed = 0;

void print_tests_summary()
{
    printf("Passed %d tests from %d total.\n", tests_passed, tests_total);
}

void test_read()
{
    int a[] = {1, 23, 445, 82, 29};
    
    liu7st list = liu7st_create();
    for (int i = 0; i < 5; i++)
        liu7st_append(&list, &a[i]);

    int i = 0, all_equal = 1;
    LIU7ST_FOREACH(int**, it, &list)
        all_equal &= **it == a[i++];

    TEST(i == 5 && all_equal);
}

void test_write()
{
    int a[] = {1, 23, 445, 82, 29};
    
    liu7st list = liu7st_create();
    for (int i = 0; i < 5; i++)
        liu7st_append(&list, &a[i]);

    LIU7ST_FOREACH(int**, it, &list)
        **it = 42;

    int all_equal = 1;
    for (int i = 0; i < 5; i++)
        all_equal &= a[i] == 42;

    TEST(all_equal);
}

int main()
{
    test_read();
    test_write();

    print_tests_summary();

    return !(tests_total == tests_passed);
}
