#include "liu7st.h"
#include <stdio.h>

int liu7st_has_cycle(liu7st list)
{
    liu7st_element current_element;
    if (list.size <= 0)
    {
        return 0;
    }

    if (list.first == NULL || list.last == NULL)
    {
        return 0;
    }

    current_element = *(list.head);
    for (int i = 0; i < list.size; i++)
    {
        if (current_element.next == NULL)
        {
            return 0;
        }
        current_element = *(current_element.next);

    }
}
