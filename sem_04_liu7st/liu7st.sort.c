#include "liu7st.h"

/**
 * @fn void liu7st_sort(liu7st *list, int (*comp)(const void*, const void*))
 * @brief Сортировка списка пузырьком
 * @param list список для сортировки
 * @param comp указатель на функцию-компаратор
 */
void liu7st_sort(liu7st *list, int (*comp)(const void*, const void*))
{
    liu7st_element *elem = list->first;
    int flag = 0;

    for (int i = 0; i < list->size; i++)
    {
        for (int j = 0; j < list->size - i - 1; j++)
        {
            liu7st_element *nelem = elem->next;

            if (comp(elem->data, nelem->data) > 0)
            {
                if (elem == list->first)
                    list->first = nelem;
                else
                    elem->prev->next = nelem;

                if (nelem == list->last)
                    list->last = elem;
                else
                    nelem->next->prev = elem;

                nelem->prev = elem->prev;
                elem->next = nelem->next;
                elem->prev = nelem;
                nelem->next = elem;

                flag = 1;

                elem = nelem;
            }

            elem = elem->next;
        }

        elem = list->first;

        if (!flag)
            break;

        flag = 0;
    }
}

