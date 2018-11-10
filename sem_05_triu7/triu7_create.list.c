#include "triu7.h"

int main()
{
    int x = 5;
    void *data = &x;
    triu7 tree = triu7_create(data);
    
    if (triu7.data == data && triu7.num_of_leaves == 1 && triu7.leavs == NULL)
        return SUCCESS;
    
    return FAILED;
}
