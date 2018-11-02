#include "liu7st.h"

int liu7st_check(liu7st list)
{
    int result = 0;

    if (list.first == NULL && list.last == NULL && list.size != 0)
        result |= LIU7ST_INVALID_COUNT;

    if (list.first != NULL || list.last != NULL)
    {
        result = LIU7ST_FIRST_UNREACHABLE | LIU7ST_LAST_UNREACHABLE;

        if (list.first == NULL)
            result |= LIU7ST_MISSED_FIRST | LIU7ST_INVALID_COUNT;

        if (list.last == NULL)
            result |= LIU7ST_MISSED_LAST;
    }

    if (list.first != NULL)
    {
        if (list.first->prev != NULL)
            result |= LIU7ST_INVALID_FIRST;

        liu7st_element *p1 = list.first, *p2 = p1;

        int end_found = 0;
        int size = 1;

        result |= LIU7ST_CYCLED;

        do
        {
            p1 = p1->next;

            for (int i = 0; i < 2; i++)
            {
                if (p2 == list.last)
                    result &= ~LIU7ST_LAST_UNREACHABLE;

                if (p2->next == NULL)
                {
                    result &= ~LIU7ST_CYCLED;
                    end_found = 1;
                    break;
                }

                if (p2->next->prev != p2)
                    result |= LIU7ST_NONLINEAR;

                p2 = p2->next;
                size++;
            }
        } 
        while (p1 != p2 && !end_found);

        if (!end_found)
        {
            liu7st_element *meet = p1;
            p1 = list.first;
            
            int meet_reached = 0;
            int linear_segment_size = 1, cycle_size = 1;

            while (p1 != p2)
            {
                p1 = p1->next;
                linear_segment_size++;

                p2 = p2->next;
                meet_reached |= p2 == meet;

                if (!meet_reached)
                    cycle_size++;
            }

            while (!meet_reached && p2 != meet)
            {
                cycle_size++;
                p2 = p2->next;
            }

            size = cycle_size + linear_segment_size;
        }

        if (list.size != size)
            result |= LIU7ST_INVALID_COUNT;
    }

    if (list.last != NULL)
    {
        if (list.last->next != NULL)
            result |= LIU7ST_INVALID_LAST;

        result |= LIU7ST_BACK_CYCLED;
        
        liu7st_element *p1 = list.last, *p2 = p1;
        
        int begin_found = 0;

        do
        {
            p1 = p1->prev;

            for (int i = 0; i < 2; i++)
            {
                if (p2 == list.first)
                    result &= ~LIU7ST_FIRST_UNREACHABLE;

                if (p2->prev == NULL)
                {
                    result &= ~LIU7ST_BACK_CYCLED;
                    begin_found = 1;
                    break;
                }

                if (p2->prev->next != p2)
                    result |= LIU7ST_NONLINEAR;

                p2 = p2->prev;
            }
        } 
        while (p1 != p2 && !begin_found);
    }

    return result;
}
