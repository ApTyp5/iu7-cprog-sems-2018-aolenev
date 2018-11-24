#include "triu7.h"

int main()
{
    int x = 5;
    void *data = &x;
    triu7_ptr tree = triu7_create(data);
    
    if (tree->data == data && tree->leavs->size == 0 && tree->leavs == NULL)
        return IU7_SUCCESS;
    
    return IU7_FAIL;
}
