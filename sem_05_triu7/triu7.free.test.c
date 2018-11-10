#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

int test_free(triu7 *tree)
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
    triu7 *tree = malloc(sizeof(triu7));

    tree->data = malloc(sizeof(int));
    tree->num_of_leaves = 3;
    tree->leavs = malloc(tree->num_of_leaves * sizeof(triu7*));

    for (int i = 0; i < tree->num_of_leaves; i++)
    {
        (tree->leavs)[i] = malloc(sizeof(triu7));
    }

    printf("%d\n", test_free(tree));

    int *data = malloc(sizeof(int));
    tree = triu7_create(data);
    printf("%d\n", test_free(tree));

    return 0;
}