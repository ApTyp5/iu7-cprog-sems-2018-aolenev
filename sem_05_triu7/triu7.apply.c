#include "triu7.h"

int triu7_apply(triu7 *tree_head, void func(void*))
{
    if (tree_head == NULL)
        return WRONG_TREE;

    if (func == NULL)
        return WRONG_FUNCTION;

    func(tree_head->data);

    for (int i = 0; i < num_of_leaves; i++)
    {
        triu7_apply(tree_head->leavs[i], func);
    }

    return SUCCESS;
}

