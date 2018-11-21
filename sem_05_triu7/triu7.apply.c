#include "triu7.h"

/*
 * Применяет функцию к данным всех узлов деревьев
 *
 * @param tree_head [out]
 * @param func [in]
 *
 * @return Возвращает код ошибки при некорректных данных и SUCCESS в случае успеха
 */

int triu7_dat_apply(triu7_ptr node, void (*func)(void*))
{
    if (tree_head == NULL)
        return WRONG_TREE;

    if (func == NULL)
        return WRONG_FUNCTION;

    for (int i = 0; i < darrliu7_len(node->con_wei); i++)
    {
        triu7_apply(node->leavs[i], func);
    }

    func(node->data);

    return SUCCESS;
}

