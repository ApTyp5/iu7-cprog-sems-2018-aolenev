#include "liu7st.h"
#include <stdio.h>

/*
* \brief Определение наличия зацикленности списка
* \param [in] list - Список, который принимается в качестве испытуемого
* \return 0 - если нет цикла. 1 - если есть цикл.
*/
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

    if (list.last->next == list.first || list.first->prev == list.last)
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

    if (counter > list.size + 1)
    {
        int it_1 = 0, it_2 = 0;
        int found = 0;

        while (current_element->next != NULL && (found == 0 || it_1 < list.size + 1))
        {
            it_1 += 1;
            it_1 %= list.size;

            it_2 += 2;
            it_2 %= list.size;
 
            if (it_1 == it_2)
                found = 1;
        }

        return found == 1;
    }

    return 0;
}

