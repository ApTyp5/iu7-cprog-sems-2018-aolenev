#include <stdio.h>
#include "liu7st.h"

/**
 * @fn int get_test_int(liu7st *list, int *count)
 * @brief тест функции get, которая получает элемент типа int списка по индексу
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int get_test_int(liu7st list, int *count)
{
    void *result;
    
    result = liu7st_get(list, 0);
    
    if (result == NULL)
    {
        *count += 1;
        return 1;
    }
    else
    {    
        *count += 1;
        return (*(int*)result == 5);
    }
}

/**
 * @fn int get_test_int(liu7st *list, int *count)
 * @brief тест функции get, которая получает элемент типа double списка по индексу
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int get_test_double(liu7st list, int *count)
{
    void *result;
    
    result = liu7st_get(list, 2);
    
    if (result == NULL)
    {
        *count += 1;
        return 0;
    }
    else
    {    
        *count += 1;
        return (*(double*)result == 3.2);
    }
}

/**
 * @fn int get_test_int(liu7st *list, int *count)
 * @brief тест функции get, в которой берется элемент по некорректному индексу 
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int get_test_wrong(liu7st list, int *count)
{
    void *result;
    
    result = liu7st_get(list, 10);
    *count += 1;
    return (result == NULL);
}

int main()
{
    int count = 0, success = 0;
    liu7st list_1, list_2, list_3;
    list_1 = liu7st_create();
    list_2 = liu7st_create();
    list_3 = liu7st_create();
    
    int a[3] = {5, 12, 4};
    liu7st_append(&list_1, a);
    liu7st_append(&list_1, a + 1);
    liu7st_append(&list_1, a + 2);
    
    double b[3] = {5.3, 4.7, 3.2};
    liu7st_append(&list_2, b);
    liu7st_append(&list_2, b + 1);
    liu7st_append(&list_2, b + 2);
    
    int c[3] = {1, 2, 3};
    liu7st_append(&list_3, c);
    liu7st_append(&list_3, c + 1);
    liu7st_append(&list_3, c + 2);
    
    success += get_test_int(list_1, &count);
    success += get_test_double(list_2, &count);
    success += get_test_wrong(list_3, &count);
    
    printf("\nGet func test:\n");
    
    if (success == count)
        printf("Test passed.\nPassed tests: %d/%d\n", success, count);
    else
        printf("Test failed.\nPassed tests: %d/%d\n", success, count);
    
    return 0;
}