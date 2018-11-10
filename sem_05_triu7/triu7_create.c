#include "triu7.h"

triu7* triu7_create(void *data)
{
    triu7 tree;
    tree.data = data;
    tree.num_of_leaves = 0;
    tree.leavs = NULL;

    return tree;
}
