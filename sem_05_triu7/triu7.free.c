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
    if (elem != NULL)
        do
        {
            triu7_ptr subroot = elem->data;
            liu7st_element *buf = elem->next;
            triu7_free(&subroot);
            elem->data = subroot;
            free(elem);
            elem = buf;
        } while (elem != NULL);
	
    free((*root)->leavs);
    darriu7_release(((*root)->con_wei));
    free((*root)->data);
    free(*root);
	*root = NULL;
}
