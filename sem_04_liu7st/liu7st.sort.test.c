#include <stdio.h>

#include "liu7st.h"

/**
 * @fn int int_comp(const void *a, const void *b)
 * @brief Сравнение двух int
 * @param a первое число
 * @param b второе число
 * @return разница между a и b
 */
int int_comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/**
 * @fn int double_comp(const void *a, const void *b)
 * @brief Сравнение двух double
 * @param a первое число
 * @param b второе число
 * @return разница между a и b
 */
int double_comp(const void *a, const void *b)
{
    return (*(double*)a - *(double*)b > 0);
}

/**
 * @fn int sort_test_1(liu7st *list, int *count)
 * @brief тест сортировки (обратно упоряоченного списка) для типа int
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int sort_test_1(liu7st *list, int *count, int (*comp)(const void*, const void*))
{
    int key = 0;
    liu7st_sort(list, int_comp);
    liu7st_element *elem = list->first;
    
    for (int i = 0; i < list->size - 1; i++)
    {
        liu7st_element *nelem = elem->next;
        if (comp(elem->data, nelem->data) > 0)
        {
            key = 1;
            break;
        }
    }
    *count += 1;
    
    return (key == 0);
}

/**
 * @fn int sort_test_2(liu7st *list, int *count)
 * @brief тест сортировки (упорядоченного списка) для типа int
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int sort_test_2(liu7st *list, int *count, int (*comp)(const void*, const void*))
{
    int key = 0;
    liu7st_sort(list, int_comp);
    liu7st_element *elem = list->first;
    
    for (int i = 0; i < list->size; i++)
    {
        liu7st_element *nelem = elem->next;
        if (comp(elem->data, nelem->data) > 0)        
        {
            key = 1;
            break;
        }
    }
    *count += 1;
    
    return (key == 0);
}

/**
 * @fn int sort_test_3(liu7st *list, int *count)
 * @brief тест сортировки (обратно упорядоченного списка) для типа double
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int sort_test_3(liu7st *list, int *count, int (*comp)(const void*, const void*))
{
    int key = 0;
    
    liu7st_sort(list, double_comp);
    liu7st_element *elem = list->first;
    
    for (int i = 0; i < list->size; i++)
    {
        liu7st_element *nelem = elem->next;

        if (comp(elem->data, nelem->data) > 0)        
        {
            key = 1;
            break;
        }
    }
    *count += 1;
    
    return (key == 0);
}

/**
 * @fn int sort_test_4(liu7st *list, int *count)
 * @brief тест сортировки (упорядоченного списка) для типа double
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int sort_test_4(liu7st *list, int *count, int (*comp)(const void*, const void*))
{
    int key = 0;
    
    liu7st_sort(list, double_comp);
    liu7st_element *elem;
    elem = list->first;
    
    for (int i = 0; i < list->size - 1; i++)
    {
        liu7st_element *nelem = elem->next;
   
        if (comp(elem->data, nelem->data) > 0)        
        {
            key = 1;
            break;
        }
    }
    *count += 1;
    
    return (key == 0);
}

int main()
{
    int count = 0, success = 0;
    liu7st list_1, list_2, list_3, list_4;
    list_1 = liu7st_create();
    list_2 = liu7st_create();
    list_3 = liu7st_create();
    list_4 = liu7st_create();
    
    int a[3] = {3, 2, 1};
    liu7st_append(&list_1, a);
    liu7st_append(&list_1, a + 1);
    liu7st_append(&list_1, a + 2);
    
    liu7st_append(&list_2, a + 2);
    liu7st_append(&list_2, a + 1);
    liu7st_append(&list_2, a);
    
    double b[3] = {5.0, 4.7, 3.2};
    liu7st_append(&list_3, b);
    liu7st_append(&list_3, b + 1);
    liu7st_append(&list_3, b + 2);
    
    liu7st_append(&list_4, b + 2);
    liu7st_append(&list_4, b + 1);
    liu7st_append(&list_4, b);
    
    success += sort_test_1(&list_1, &count, int_comp);
    success += sort_test_2(&list_2, &count, int_comp);
    success += sort_test_3(&list_3, &count, double_comp);
    success += sort_test_4(&list_4, &count, double_comp);
    
    printf("\nSort func test:\n");
    
    if (success == count)
        printf("Test passed.\nPassed tests: %d/%d\n", success, count);
    else
        printf("Test failed.\nPassed tests: %d/%d\n", success, count);
    
    // liu7st_free(&list_1, free);
    // liu7st_free(&list_2, free);
    // liu7st_free(&list_3, free);
    // liu7st_free(&list_4, free);
    
    return 0;
}