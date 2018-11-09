#include <stdio.h>

#include "liu7st.h"

void negative_test(void);

void positive_test(void);

void free_data(void* data);

int main(void)
{
    negative_test();
    positive_test();

    return 0;
}

void negative_test(void)
{
    liu7st list = liu7st_create();

    liu7st_free(&list, free);

    printf("Negative test success.\n");
}

void positive_test(void)
{
    int value[] = {1, 2, 3, 4, 5};
    liu7st list = liu7st_create();

    for (int i = 0; i < 5; i++)
        liu7st_append(&list, value + i);
    
    liu7st_free(&list, free_data);

    printf("Positive test success.\n");
}

void free_data(void *data)
{
    return;
}
