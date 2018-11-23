#include "triu7.h"

triu7_ptr triu7_create(void *data)
{
    triu7_ptr tree;
    tree->data = data;
    tree->con_wei = darriu7_create(0);
    tree->leavs = NULL;

    return tree;
}
