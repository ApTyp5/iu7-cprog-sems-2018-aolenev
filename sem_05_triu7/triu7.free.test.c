#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

int test_free(triu7_ptr tree)
{
    triu7_free(tree);

    if (tree == NULL)
        return 1;
    else
        return 0;
}


int main(void)
{
    printf("Total tests : %d\n", 2);
    triu7_ptr tree = malloc(sizeof(triu7_node));

    tree->data = malloc(sizeof(int));
    tree->leavs = malloc(3 * sizeof(triu7_ptr));

    for (int i = 0; i < 3; i++)
    {
        (tree->leavs)[i] = malloc(sizeof(triu7_node));
    }

    printf("%d\n", test_free(tree));

//    int *data = malloc(sizeof(int));
//    tree = triu7_create(data);
//    printf("%d\n", test_free(tree));

    return 0;
}