#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn triu7_free(triu7_ptr root)
 * @brief Очищает память из-под дерева.
 * @param [in] узел дерева.
 */
void triu7_free(triu7_ptr root)
{
    if (root == NULL || root->data == NULL || root->con_wei == NULL || \
        root->leavs == NULL)
    {
        return;
    }

    liu7st_element *now = root->leavs->first;

    while (now != NULL && now->data != NULL)
    {
        free(root->data);
        free(root->con_wei);
        free(root->leavs);
        now = now->next;
    }

    free(root);
}
