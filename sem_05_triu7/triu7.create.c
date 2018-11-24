#include "triu7.h"

triu7_ptr triu7_create(void *data)
{
    triu7_ptr tree = malloc(sizeof(triu7_node));
    if (!tree)
	return NULL;

    tree->data = data;

    tree->con_wei = darriu7_create(0);
    if (tree->con_wei == NULL)
    {
        free(tree);
        return NULL;
    }


    tree->leavs = malloc(sizeof(liu7st));
    if (tree->leavs == NULL)
    {
        darriu7_release(tree->con_wei);
        free(tree);
        return NULL;
    }

    *(tree->leavs) = liu7st_create();

    return tree;
}
