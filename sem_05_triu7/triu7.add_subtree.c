#include <triu7.h>


int triu7_add_subtree(triu7_ptr node, triu7_ptr subroot, int weight)
{
    if (node == NULL || subroot == NULL)
    {
        return IU7_FAIL;
    }

    liu7st_append(node->leavs, subroot);
    node->con_wei = darriu7_append(node->con_wei, weight);

    return IU7_SUCCESS;
}

