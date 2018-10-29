#include <stdio.h>

#include "liu7st.h"

void test_liu7st_free();

int main(void)
{
    test_liu7st_free();

    return 0;
}

void test_liu7st_free()
{
    int value = 0;
    liu7st list = liu7st_create();

    printf("Testing liu7st_free. ");

    liu7st_insert(&list, &value, 1);
    liu7st_free(&list, free);

    printf("Success.\n");
}