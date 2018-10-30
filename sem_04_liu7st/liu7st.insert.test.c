#include "liu7st.h"

void insert_test1(int *success_tests)
{
    liu7st list = liu7st_create();
    int success = 0;
    int data;
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        data = i;
        liu7st_insert(&list, &data, i);
    }
    void *pointer;
    
    for (int i = 0; i < size; i++)
    {
        liu7st_get(&list, i, &pointer);
        if (*((int*)pointer) = i)
            success++;
    }
    
    if (success == size)
        (*success_tests)++;
}

void insert_test2(int *success_tests)
{
    liu7st list = liu7st_create();
    int i = -1;
    int data = 2;
    int code_mistake = liu7st_insert(&list, &data, i);
    
    if ((code_mistake != 0) && (list->size == 0))
        (*success_tests)++;
}

void insert_test3(int *success_tests)
{
    liu7st list = liu7st_create();
    int i = 1;
    int data = 2;
    int code_mistake = liu7st_insert(&list, &data, i);
    
    if ((code_mistake != 0) && (list->size == 0))
        (*success_tests)++;
}

void insert_test4(int *success_tests)
{
    liu7st list = liu7st_create();
    int success = 0;
    float data[] = { 1.5, 5.4, -2.3, 0.8, 9.7 };
    int size = 5;
    for (int i = 0; i < size; i++)
        liu7st_insert(&list, &data[i], i);
    void *pointer;
    
    for (int i = 0; i < size; i++)
    {
        liu7st_get(&list, i, &pointer);
        if (*((float*)pointer) = data[i])
            success++;
    }
    
    if (success == size)
        (*success_tests)++;
}

int main(void)
{
    int success_tests = 0;
    int count_tests = 4;
    
    insert_test1(&success_tests);
    insert_test2(&success_tests);
    insert_test3(&success_tests);
    insert_test4(&success_tests);
    
    printf("%d of %d tests passed successfully.\n", success_tests, count_tests);
    
    return 0;
}
