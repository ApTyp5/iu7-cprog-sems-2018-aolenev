#include "liu7st.h"

void incor_i_less_null()
{
    char name[] = "incor_i_less_null";
    liu7st list;
    
    list.size = 5;
    int pos = -10;
    void *data;
    
    int err = liu7st_set(list, pos, data);
    
    if (err != SET_ERROR)
        printf("%s: Test failed\n Actual: SUCCESS\n Expected: SET_ERROR\n", name);
    else
        printf("%s: Test success\n", name);
    
}

void incor_i_more_size()
{
    char name[] = "incor_i_more_size";
    liu7st list;
    
    list.size = 5;
    int pos = 10;
    void *data;
    
    int err = liu7st_set(list, pos, data);
    
    if (err != SET_ERROR)
        printf("%s: Test failed\n Actual: SUCCESS\n Expected: SET_ERROR\n", name);
    else
        printf("%s: Test success\n", name);
}

void correct_test()
{
    char name[] = "correct_test";
    
    liu7st list = liu7st_create();
    void *data = NULL;
    int err, is_continue = 1;
    
    liu7st_append(&list, data);
    liu7st_append(&list, data);
    liu7st_append(&list, data);
    
    int new_data = 3;
    
    for (int i = 0; i < list.size; i++)
    {
        err = liu7st_set(list, i, (void*)(&new_data));
        
        if (err != SUCCESS)
        {
            is_continue = 0;
            break;
        }
    }
    
    if (!is_continue)
    {
        printf("%s: Test failed\n Actual: SUCCESS\n Expected: SET_ERROR\n", name);
        return;
    }
    
    liu7st_element *head;
    head = list.first;
    
    for (int i = 1; i < list.size; i++)
    {
        if (*((int*)(head->data)) != new_data)
        {
            printf("%s: Test failed\n Actual: %d\n Expected: %d\n",
                name, *((int*)(head->data)), new_data);
            return;
        }
        
        head = head->next;
    }
    
    printf("%s: Test success\n", name);
}

void start_test()
{
    incor_i_less_null();
    incor_i_more_size();
    correct_test();
}

int main()
{
    printf("Testing liu7st_set:\n");
    start_test();
}
