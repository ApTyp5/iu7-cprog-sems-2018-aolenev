#include "triu7.h"
#include <stdio.h>
#include <stdlib.h>

void free_data(void *data)
{
    return;
}

/**
 * @fn triu7_free(triu7_ptr root)
 * @brief Очищает память из-под дерева.
 * @param root [in] узел дерева.
 */
void triu7_free(triu7_ptr *root)
{
    if ((*root) == NULL || (*root)->data == NULL || (*root)->con_wei == NULL || \
        (*root)->leavs == NULL)
    {
        return;
    }

    liu7st_element *elem = (*root)->leavs->first;
    do
    {
        triu7_free(&elem->data);
        elem = elem->next;
    } while (elem != (*root)->leavs->last->next);
	
    liu7st_free((*root)->leavs, free_data);
    darriu7_release(((*root)->con_wei));
    free((*root)->data);
    free(*root);
	*root = NULL;
}
