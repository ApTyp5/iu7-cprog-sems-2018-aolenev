#include "triu7.h"

int triu7_apply(triu7 tree_head, void func(void*))
{
    func(tree_head);

    for (int i = 0; i < num_of_leaves; i++)
    {
        triu7_apply(*(leavs[i]), func);
    }

    return SUCCESS;
}

