#include "triu7.h"
#define TRUE 1
#define FALSE 0

typedef struct {
    triu7 **pointers;
    int count;
} PointersSet;

int contains(PointersSet *set, triu7 *pointer)
{
    if (set == NULL || pointer == NULL)
    {
        return FALSE;
    }

    for (int i = 0; i < set->count; i++)
    {
        if (*(set->pointers + i) == pointer)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int has_cycle(triu7 *tree)
{
    
    return FALSE;
}
