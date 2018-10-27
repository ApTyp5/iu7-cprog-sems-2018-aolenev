#include <stdio.h>

#include "liu7st.h"

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
    liu7st_append(&list, 3);
    liu7st_append(&list, 2);
    liu7st_append(&list, 1);
    
    success += sort_test(list, count)
    
    printf("\nSort func test:\n");
    
    if (success == count)
        printf("Test passed.\nPassed tests: %d/%d\n", success, count);
    else
        printf("Test failed.\nPassed tests: %d/%d\n", success, count);
    
    return 0;
}
