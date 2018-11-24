#include "triu7.h"

/*
 * Применяет функцию к данным всех узлов деревьев
 *
 * @param tree_head [out]
 * @param func [in]
 *
 * @return Возвращает код ошибки при некорректных данных и SUCCESS в случае успеха
 */

int triu7_apply(triu7_ptr node, void (*func)(void*))
{
    if (node == NULL)
        return IU7_WRONG_TREE;

    if (func == NULL)
        return IU7_WRONG_FUNCTION;

    func(node->data);

    liu7st_element *temp = node->leavs->first;

    for (; temp != NULL; temp = temp->next)
    {
        triu7_apply(temp->data, func);
    }

    return SUCCESS;
}

