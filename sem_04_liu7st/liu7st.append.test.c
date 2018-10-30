#include "liu7st.h"

#define TEST(CONDITION) \
    printf("Test %d (" #CONDITION "): %s\n", ++tests_total, CONDITION ? ++tests_passed, "passed" : "failed")

int tests_total = 0, tests_passed = 0;

int main()
{
    liu7st l = liu7st_create();
    int a = 10, b = 20;

    liu7st_append(&l, &a);
    TEST(l.size == 1 && *(int*)(l.last->data) == 10);

    liu7st_append(&l, &b);
    TEST(l.size == 2 && *(int*)(l.last->data) == 20);

    return 0;
}

