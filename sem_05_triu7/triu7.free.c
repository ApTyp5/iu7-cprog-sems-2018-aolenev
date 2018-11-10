#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

void triu7_free(triu7 *tree)
{
    if (tree->data == NULL || tree->num_of_leaves == 0 || tree->leavs == NULL)
    {
        return;
    }
    
    for (int i = 0; i < tree->num_of_leaves; i++)
    {
        if ((tree->leavs)[i] == NULL)
        {
            return;
        }
    }
    
    for (int i = 0; i < tree->num_of_leaves; i++)
    {
        free((tree->leavs)[i]);
    }
    free(tree->data);
    free(tree->leavs);
    tree->num_of_leaves = 0;
    free(tree);
}