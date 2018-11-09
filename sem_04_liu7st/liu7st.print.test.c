#include "liu7st.h"

int success_tests = 0;

int positive_test_count_print = 0;

void print_data(const void *data)
{
    positive_test_count_print++;
}

void free_data(void *data)
{
    return;
}

void positive_test(void)
{
    liu7st list = liu7st_create();

    int arr[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++)
        liu7st_append(&list, arr + i);

    liu7st_print(list, print_data);

    if (positive_test_count_print == 5)
        success_tests++;

    liu7st_free(&list, free_data);
}

void negative_test(void)
{
    liu7st list = liu7st_create();

    int code = liu7st_print(list, print_data);

    if (code == WRONG_LIST)
        success_tests++;

    liu7st_free(&list, free_data);
}

int main(void)
{
    negative_test();
    positive_test();

    if (success_tests == 2)
    {
        printf("Success test.\n");
        return SUCCESS;
    }
    else
    {
        printf("Failed test. :(\n");
        return FAILED;
    }
}
