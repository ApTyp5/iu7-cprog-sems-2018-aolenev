#include "liu7st.h"

int success_tests = 0;

void action(void *data)
{
    *(int*)data += 1;
}

void free_data(void *data)
{
    return;
}

void positive_test(void)
{
    int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    liu7st list = liu7st_create();

    for (int i = 0; i < 10; i++)
        liu7st_append(&list, a + i);

    liu7st_apply(list, 7, action);
    
    int right = 0;

    for (int i = 0; i < 10; i++)
        if (a[i] == 0 && i < 7)
            right++;
        else if (a[i] == 1 && i >= 7)
            right++;

    if (right == 10)
        success_tests++;

    liu7st_free(&list, free_data);
}

void negative_test(void)
{
    liu7st list = liu7st_create();

    int right = 0;

    if (liu7st_apply(list, 2, action) == WRONG_LIST)
        right++;

    int value = 0;

    liu7st_append(&list, &value);

    if (liu7st_apply(list, 2, action) == WRONG_INDEX)
        right++;

    if (right == 2)
        success_tests++;

    liu7st_free(&list, free_data);
}

int main(void)
{
    positive_test();
    negative_test();

    if (success_tests == 2)
    {
        printf("Test liu7st_apply SUCCESS\n");
        return SUCCESS;
    }
    else
    {
        printf("Test liu7st_apply FAILED\n");
        return FAILED;
    }
}
