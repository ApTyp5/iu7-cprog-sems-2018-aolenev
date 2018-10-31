#include "liu7st.h"

int liu7st_check(liu7st list)
{
    if ((list.first == NULL) ^ (list.last == NULL))
        return WRONG_LIST;

    if (list.first == NULL && list.last == NULL)
        return list.size == 0 ? SUCCESS : WRONG_LIST;

    if (list.first->prev != NULL || list.last->next != NULL)
        return WRONG_LIST;

    liu7st_element *p1 = list.first, *p2 = p1;
    int size = 1;

    do
    {
        p1 = p1->next;
        
        for (int i = 0; i < 2; i++)
        {
            if (p2->next == NULL)
                return list.last == p2 && list.size == size ? SUCCESS : WRONG_LIST;

            if (p2->next->prev != p2)
                return WRONG_LIST;

            p2 = p2->next;
            size++;
        }
    } 
    while (p1 != p2);

    return WRONG_LIST;
}
