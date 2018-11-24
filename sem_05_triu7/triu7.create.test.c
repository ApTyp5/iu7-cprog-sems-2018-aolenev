#include "triu7.h"

int main()
{
    int x = 5;
    void *data = &x;
    triu7_ptr tree = triu7_create(data);
    
    if (tree->data == data && tree->con_wei == darriu7_create(0)  && tree->leavs == NULL)
        return SUCCESS;
    
    return IU7_FAIL;
}
