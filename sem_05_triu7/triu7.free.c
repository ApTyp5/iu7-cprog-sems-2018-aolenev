#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn triu7_free(triu7 *tree)
 * @brief Очищает память из-под дерева.
 * @param tree указатель на корень (тип triu7).
 */
void triu7_free(triu7 *tree)
{
    if (tree == NULL || tree->data == NULL || tree->num_of_leaves == 0 || \
        tree->leavs == NULL)
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
    tree->num_of_leaves = 0;
    free(tree->leavs);
    free(tree->data);
    free(tree);    
}