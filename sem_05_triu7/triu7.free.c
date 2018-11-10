#include "triu7.h"
#include <stdio.h>

void triu7_free(triu7 *tree)
{
    if (tree->data == NULL || tree->num_of_leaves == 0 || tree->leavs == NULL)
    {
        return;
    }
    
    for (int i = 0; i < tree->num_of_leaves; i++)
    {
        tree->data = NULL;
        tree->leavs = NULL;
    }
    
    tree->num_of_leaves = 0;
}