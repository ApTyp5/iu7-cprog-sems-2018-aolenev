#include "liu7st.h"

void free_data(void *data)
{
    return;
}

void print_data(const void *data)
{
    printf("%d ", *(int*)data);
}

int compare_inc(const void *data1, const void* data2)
{
    return *(int*)data1 - *(int*)data2;
}

int compare_dec(const void *data1, const void* data2)
{
    return *(int*)data2 - *(int*)data1;
}

int main(void)
{
    liu7st list = liu7st_create();

    int arr[] = {5, 9, 8, 2, 0, 6, 1, 7, 4, 3};
    printf("Start list: ");
    for (int i = 0; i < 10; i++)
        liu7st_append(&list, arr + i);
    liu7st_print(list, print_data);
    printf("\n");

    printf("Sort inc: ");
    liu7st_sort(&list, compare_inc);
    liu7st_print(list, print_data);
    printf("\n");

    printf("Sort dec: ");
    liu7st_sort(&list, compare_dec);
    liu7st_print(list, print_data);
    printf("\n");

    printf("Insert new elements: ");
    int a = 20, b = -30, c = 45;
    liu7st_insert(&list, &a, 4);
    liu7st_insert(&list, &b, 0);
    liu7st_insert(&list, &c, 9);
    liu7st_print(list, print_data);
    printf("\n");
/*
    printf("Revert list: ");
    liu7st_revert(&list);
    liu7st_print(list, print_data);
    printf("\n");
*/
    liu7st new_list = liu7st_create();
    int arr1[] = {100, 101, 102, 103};

    printf("New list: ");
    for (int i = 0; i < 4; i++)
        liu7st_append(&new_list, arr1 + i);
    liu7st_print(new_list, print_data);
    printf("\n");

    printf("Concat list: ");
    liu7st list_sum = liu7st_concat(list, new_list);
    liu7st_print(list_sum, print_data);
    printf("\n");

    printf("Sort dec: ");
    liu7st_sort(&list_sum, compare_dec);
    liu7st_print(list_sum, print_data);
    printf("\n");
    printf("Set to 0: ");

    int arr_new[17] = {0};
    for (int i = 0; i < 17; i++)
        liu7st_set(list_sum, i, arr_new + i);
    liu7st_print(list_sum, print_data);
    printf("\n");

    printf("Has cycle?: %d\n", liu7st_has_cycle(list_sum));
    
    liu7st_free(&list, free_data);
    liu7st_free(&new_list, free_data);
    liu7st_free(&list_sum, free_data);

    return SUCCESS;
}
