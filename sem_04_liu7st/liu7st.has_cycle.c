#include "liu7st.h"
#include <stdio.h>

int liu7st_has_cycle(liu7st list)
{
    if (list.size <= 0)
    {
        return 0;
    }

    if (list.first == NULL || list.last == NULL)
    {
        return 0;
    }

    if (list.last->next == list.first || list.first->prev = list.last)
    {
        return 1;
    }

    liu7st_element current_element = *(list.first);
    int counter = 0;
    while (current_element->next != NULL || counter <= list.size + 1)
    {
        counter++;
    }

    if (current_element->next == NULL && counter < list.size - 1)
    {
        return 0;
    }

    // if (counter > list.size + 1)
    // {
    //     int it_1 = 0, it_2 = 0;
    //
    //     while (it_1 <= it_2 || it_1 )
    //     {
    //         it_1 += 1;
    //         it_2 += 2;
    //
    //     }
    //
    //     return 1;
    // }

    return 0;
}
