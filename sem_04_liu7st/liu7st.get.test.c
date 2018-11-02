#include <stdio.h>

#include "liu7st.h"

/**
 * @fn int get_test_int(liu7st *list, int *count)
 * @brief тест функции get, которая получает элемент типа int списка по индексу
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int get_test_int(liu7st *list, int *count)
{
    int result;
    
    result = get(&list, 2);
    return (result == 4);
}

/**
 * @fn int get_test_int(liu7st *list, int *count)
 * @brief тест функции get, которая получает элемент типа double списка по индексу
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int get_test_double(liu7st *list, int *count)
{
    double result;
    
    result = get(&list, 0);
    return (result == 5.3);
}

int main()
{
    int count = 0, success = 0;
    liu7st list_1, list_2;
    list_1 = liu7st_create();
    list_2 = liu7st_create();
    
    int a[3] = {5, 12, 4};
    liu7st_append(&list_1, a);
    liu7st_append(&list_1, a + 1);
    liu7st_append(&list_1, a + 2);
    
    double b[3] = {5.3, 4.7, 3.2};
    liu7st_append(&list_2, b);
    liu7st_append(&list_2, b + 1);
    liu7st_append(&list_2, b + 2);
    
    success += get_test_int(&list_1, &count);
    success += get_test_double(&list_1, &count);
    
    liu7st_free(&list_1);
    liu7st_free(&list_2);
    
    printf("\nGet func test:\n");
    
    if (success == count)
        printf("Test passed.\nPassed tests: %d/%d\n", success, count);
    else
        printf("Test failed.\nPassed tests: %d/%d\n", success, count);
    
    return 0;
}