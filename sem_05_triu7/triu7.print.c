#include "triu7.h"

int count_of_tab = 0;

/*
 * Выводит дерево
 *
 * @param node [in]
 * @param pdata [in]
 *
 * @return Возвращает IU7_WRONG_TREE если некорректное дерево
 * и SUCCESS при успехе
 */

int triu7_print(triu7_ptr node, void (*pdata)(void*))
{
    if (node == NULL)
        return IU7_WRONG_TREE;

    for (int i = 0; i < count_of_tab; i++)
        printf("    ");

    pdata(node->data);

    liu7st_element *temp = node->leavs->first;
    for (; temp != NULL; temp = temp->next)
    {
        count_of_tab++;
        triu7_print(temp->data, pdata);
        count_of_tab--;
    }

    return SUCCESS;
}

