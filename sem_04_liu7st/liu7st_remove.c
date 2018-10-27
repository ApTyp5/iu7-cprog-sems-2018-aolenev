#include "liu7st_remove.h"
#include "liu7st.h"

int liu7st_remove(striu7st *list, int i)
{
    if (i >= list->size || i < 0)
        return WRONG_INDEX;
    
    liu7st_element *p = list->first;
    
    for (int a = 0; a < i; a++)
    {
        p = p->next;
    }
    
    free(p->data);
    
    if (i)
        (p->prev)->next = p->next;
    else
        list->begin = p->next;
   

    if (p != list->end)
        (p->next)->prev = p->prev;
    else
        list->end = p->prev;
    
    (list->size)--;
    
    return SUCCESS;
}