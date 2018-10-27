#include "liu7st.h"

void liu7st_sort(liu7st *list)
{
    liu7st_element *elem = list->first;
    
    for (int i = 0; i < list->size; i++)
    {
        for (int j = 0; j < list->size - i - 1; j++)
        {
            liu7st_element *nelem = elem->next;
            if (elem->data > nelem->data)
            {
                if (elem == list->first)
                    list->first = nelem;
                if (nelem == list->last)
                    list->last = elem;
                nelem->prev = elem->prev;
                elem->next = nelem->next;
                elem->prev = nelem;
                nelem->next = elem;
            }
        }

        elem = list->first;
    }
}

