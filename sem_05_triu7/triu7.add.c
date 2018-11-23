#include "triu7.h"

int triu7_add(triu7_ptr node, void *new_data, int weight)
{
    if (node == NULL || new_data == NULL)
        return IU7_FAIL;

    darriu7 new_weights = darriu7_append(node->con_wei, weight);
    if (new_weights == NULL)
        return IU7_FAIL;

    node->con_wei = new_weights;
    liu7st_append(node->leavs, triu7_create(new_data));
    return IU7_SUCESS;
}
