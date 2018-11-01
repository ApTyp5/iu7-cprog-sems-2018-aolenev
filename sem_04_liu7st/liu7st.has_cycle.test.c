#include "liu7st.h"
#include <stdio.h>

void test_empty(int *passed)
{
    int expected = 0;
    liu7st list;
    
    list.size = 0;
    list.first = NULL;
    list.last = NULL;

    if (liu7st_has_cycle(list) == expected)
    {
        *passed = *passed + 1;
    }
    else
    {
	printf("Empty test not passed\n");
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
    else
    {
	printf("No cycle test not passed\n");    
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
    else
    {
	printf("Circular test not passed\n");
    }
    
    free(list.first->next->next);
    free(list.first->next);
    free(list.first);
}

int main()
{
    int passed = 0;
    
    test_empty(&passed);
    test_no_cycle(&passed);
    test_circular(&passed);
    
    if (passed != 3)
    {
        printf("Error\n");
        return FAILED;
    }
    
    return SUCCESS;
}
