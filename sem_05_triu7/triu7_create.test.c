#include "triu7.h"

int main()
{
    int x = 5;
    void *data = &x;
    triu7 *tree = triu7_create(data);
    
    if (tree->data == data && tree->num_of_leaves == 0 && tree->leavs == NULL)
        return SUCCESS;
    
    return FAIL;
}
