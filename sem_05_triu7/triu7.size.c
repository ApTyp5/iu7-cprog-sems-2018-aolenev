#include "triu7.h"

static int triu7_size_recursion(triu7_ptr node)
{
    int n = 0;
    
    for (int i = 0; i < (node->leavs)->size; i++)
        n += triu7_size_recursion((triu7_ptr)liu7st_get(*(node->leavs), i));
    
    return n + 1;
}

int triu7_size(triu7_ptr node)
{
    if (triu7_has_cycle(node) == IU7_TRUE)
        return IU7_WRONG_TREE;
    
    return triu7_size_recursion(node);
}
