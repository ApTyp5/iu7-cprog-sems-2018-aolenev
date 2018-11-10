#include <time.h>
#include <stdlib.h>

#include "liu7st.h"

#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

#define STRESS_SIZE 10000000

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

void action(void *data)
{
    *(int*)data -= 23;
}

int main(void)
{
    srand(time(NULL));

    clock_t start = clock();

    liu7st list = liu7st_create();

    int arr[] = {5, 9, 8, 2, 0, 6, 1, 7, 4, 3};
    printf("Start list: ");
    for (int i = 0; i < 10; i++)
        liu7st_append(&list, arr + i);
    liu7st_print(list, print_data);
    printf("\n");

    printf("Has cycle?: %d\n", liu7st_has_cycle(list));

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

    printf("Revert list: ");
    list = liu7st_revert(list);
    liu7st_print(list, print_data);
    printf("\n");

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

    printf("Get[0]: %d;", \
            *(int*)liu7st_get(list_sum, 0));

    printf("Remove some elements [16, 10, 5, 0]: ");
    liu7st_remove(&list_sum, 16, free_data);
    liu7st_remove(&list_sum, 10, free_data);
    liu7st_remove(&list_sum, 5, free_data);
    liu7st_remove(&list_sum, 0, free_data);
    liu7st_print(list_sum, print_data);
    printf("\n");

    printf("Set to 0: ");
    int arr_new[17] = {0};
    for (int i = 0; i < 17; i++)
        liu7st_set(list_sum, i, arr_new + i);
    liu7st_print(list_sum, print_data);
    printf("\n");

    printf("Has cycle?: %d\n", liu7st_has_cycle(list_sum));

    printf("Apply -23 from 5th element: ");
    liu7st_apply(list_sum, 5, action);
    liu7st_print(list_sum, print_data);
    printf("\n");

    printf("Apply -23 from 9th element: ");
    liu7st_apply(list_sum, 9, action);
    liu7st_print(list_sum, print_data);
    printf("\n");

    liu7st_free(&list, free_data);
    liu7st_free(&new_list, free_data);
    liu7st_free(&list_sum, free_data);

    clock_t end = clock();

    printf(GREEN "\nliu7st time: %f sec\n", (float)(end - start) / CLOCKS_PER_SEC);
    printf(RESET "\n");

    printf("%d elements test: \n", STRESS_SIZE);

    int *stress_array = malloc(STRESS_SIZE * sizeof(int));

    for (int i = 0; i < STRESS_SIZE; i++)
        stress_array[i] = rand() % 1000;

    clock_t stress_start = clock();
    
    liu7st stress_list = liu7st_create();

    for (int i = 0; i < STRESS_SIZE; i++)
        liu7st_append(&stress_list, stress_array + i);

    liu7st_apply(stress_list, 0, action);

    liu7st_free(&stress_list, free_data);

    clock_t stress_end = clock();

    printf(GREEN "\nliu7st time: %f sec\n", (float)(stress_end - stress_start) / CLOCKS_PER_SEC);
    printf(RESET "\n");

    free(stress_array);

    return SUCCESS;
}
