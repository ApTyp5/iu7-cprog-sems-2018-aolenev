#include "triu7.h"

triu7_ptr triu7_create(void *data)
{
    triu7_ptr tree = malloc(sizeof(triu7_node));

    if (!tree)
	return NULL;

    tree->data = data;
    tree->con_wei = darriu7_create(0);
    tree->leavs = liu7st_create();

    return tree;
}
