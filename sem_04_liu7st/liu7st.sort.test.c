#include <stdio.h>

#include "liu7st.h"

/**
 * @fn int sort_test(liu7st *list, int *count)
 * @brief тест сортировки
 * @param list список
 * @param count счетчик удачных тестов
 * @return результат теста
 */
int sort_test(liu7st *list, int *count)
{
    int key = 0;
    liu7st_element *elem = list->first;
    liu7st_sort(list);
    
    for (int i = 0; i < list->size; i++)
    {
        liu7st_element *nelem = elem->next;
        if (elem->data > nelem->data)
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
    liu7st list;
    list = liu7st_create();
    int a[3] = {1, 2, 3};
    liu7st_append(&list, a);
    liu7st_append(&list, a + 1);
    liu7st_append(&list, a + 2);
    
    success += sort_test(&list, &count);
    
    printf("\nSort func test:\n");
    
    if (success == count)
        printf("Test passed.\nPassed tests: %d/%d\n", success, count);
    else
        printf("Test failed.\nPassed tests: %d/%d\n", success, count);
    
    return 0;
}