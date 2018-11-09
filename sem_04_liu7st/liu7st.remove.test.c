#include "liu7st.h"

void free_data(void *p)
{
	free(p);
}

void liu7st_remove_test(int *success)
{
    int status;
    int a[3] = {2, 3, 4};
    liu7st list = liu7st_create();
    
    liu7st_append(&list, a);
    liu7st_append(&list, a + 1);
    liu7st_append(&list, a + 2);
    
    status = liu7st_remove(&list, 1, free_data);
	
    if (list.size == 2 && *(int *)((list.first)->data) == 2 &&
        status == SUCCESS && *(int *)(((list.first)->next)->data) == 4)
        (*success)++;
    else
        printf("\nTest 1:\nexpected: n = 2\nActual: n = %d\n", list.size);
    
    status = liu7st_remove(&list, 0, free_data);
    
    if (list.size == 1 && *(int *)((list.first)->data) == 4
        && status == SUCCESS)
        (*success)++;
    else
        printf("\nTest 2:\nexpected: n = 1\nActual: n = %d\n", list.size);
    
    status = liu7st_remove(&list, 0, free_data);
    
    if (list.size == 0 && status == SUCCESS)
        (*success)++;
    else
        printf("\nTest 3:\nexpected: n = 0\nActual: n = %d\n", list.size);
    
    status = liu7st_remove(&list, 0, free_data);
    
    if (list.size == 0 && status == WRONG_INDEX)
        (*success)++;
    else
        printf("\nTest 4:\nexpected: Wrong index\nActual: %d\n", status);  
}

int main(void)
{
    int success = 0;
    int musttests = 4;

    liu7st_remove_test(&success);
    
    printf("\n Function liu7st_remove() works at %d of %d tests\n", success, musttests);

    return SUCCESS;
}