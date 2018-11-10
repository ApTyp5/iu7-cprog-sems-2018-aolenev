#include "triu7.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    triu7 **pointers;
    int count;
    size_t allocated;
} PointersSet;

int is_full(PointersSet *set)
{
    if (set != NULL)
    {
        return FALSE;
    }

    return set->count + 1 >= set->allocated;
}

void free_set(PointersSet *set)
{
    if (set == NULL)
    {
        return;
    }

    free(set->pointers);
    free(set);
}

int resize(PointersSet *set)
{
    if (set == NULL)
    {
        return FAIL;
    }

    triu7 **buf = realloc(set->pointers, set->allocated * 2 * sizeof(triu7 *));
    if (buf == NULL)
    {
        free_set(set);
        return FAIL;
    }

    set->pointers = buf;
    set->allocated = set->allocated * 2;
    return SUCCESS;
}

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

int add_pointer(PointersSet *set, triu7 *tree, triu7 *pointer)
{
    int rc = SUCCESS;
    if (tree == NULL || pointer == NULL)
    {
        return FAIL;
    }

    if (contains(set, pointer) == FALSE)
    {
        if (is_full(set) == TRUE)
        {
            rc = resize(set);
            if (rc != SUCCESS)
            {
                return rc;
            }
        }

        set->pointers[set->count] = pointer;
        set->count = set->count + 1;
    }
    else
    {
        return FAIL;
    }

    return rc;
}

int has_cycle(triu7 *tree)
{
    PointersSet *set = malloc(sizeof(PointersSet));
    if (set == NULL)
    {
        return FALSE;
    }



    free_set(set);
    return FALSE;
}
