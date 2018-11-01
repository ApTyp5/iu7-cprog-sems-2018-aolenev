#include "liu7st.h"

#define OFFSET(STRUCT, MEMBER) (size_t)(&((STRUCT*)0)->MEMBER)

void *liu7st_begin(liu7st *list)
{
    if (list == NULL)
        return NULL;
    
    return &list->first->data;
}

void *liu7st_end(liu7st *list)
{
    if (list == NULL)
        return NULL;

    return &list->last->data;
}

void *liu7st_next(void *iterator)
{
    if (iterator == NULL)
        return NULL;
    
    liu7st_element *p = (liu7st_element*)((char*)iterator - OFFSET(liu7st_element, data));

    if (p->next == NULL)
        return NULL;

    return &p->next->data;
}

void *liu7st_prev(void *iterator)
{
    if (iterator == NULL)
        return NULL;
    
    liu7st_element *p = (liu7st_element*)((char*)iterator - OFFSET(liu7st_element, data));

    if (p->prev == NULL)
        return NULL;

    return &p->prev->data;
}
