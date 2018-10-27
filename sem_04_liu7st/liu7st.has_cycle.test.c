#include "liu7st.h"
#include <stdio.h>

void test_empty(int *passed)
{
    int expected = 0;
    liu7st list;
    
    if (liu7st_has_cycle(list) == expected)
    {
        *passed = *passed + 1;
    }
}

void test_no_cycle(int *passed)
{
    int expected = 0;
    liu7st list;
    
    list.size = 3;
    list.first = malloc(sizeof(liu7st_element));
    list.first->next = malloc(sizeof(liu7st_element));
    list.first->prev = NULL;
    list.first->next->next = malloc(sizeof(liu7st_element));
    list.first->next->prev = list.first->next;
    list.first->next->next->next = NULL;
    list.first->next->next->prev = list.first->next->next->prev;
    
    if (liu7st_has_cycle(list) == expected)
    {
        *passed = *passed + 1;
    }
    
    free(list.first->next->next);
    free(list.first->next);
    free(list.first);
}

void test_circular(int *passed)
{
    int expected = 1;
    liu7st list;
    
    list.size = 3;
    list.first = malloc(sizeof(liu7st_element));
    list.first->next = malloc(sizeof(liu7st_element));
    list.first->prev = NULL;
    list.first->next->next = malloc(sizeof(liu7st_element));
    list.first->next->prev = list.first->next;
    list.first->next->next->next = list.first;
    list.first->next->next->prev = list.first->next->next->prev;
    
    if (liu7st_has_cycle(list) == expected)
    {
        *passed = *passed + 1;
    }
    
    free(list.first->next->next);
    free(list.first->next);
    free(list.first);
}

void 

int main()
{
    int passed = 0;
    
    test_empty(&passed);
    test_no_cycle(&passed);
    test_circular(&passed);
    
    
    return 0;
}
