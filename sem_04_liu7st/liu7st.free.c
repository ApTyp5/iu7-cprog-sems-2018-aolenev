#include <liu7st.h>

void liu7st_free(liu7st *list)
{
    if (list == NULL || list->first == NULL || list->last == NULL || size == 0)
        return;

    liu7st_element *walk;

    walk = list->first;
    do
    {
        walk = walk->next;

        if (walk)
        {
            free(walk->prev->data);
            free(walk->prev);
        }
    }
    while (walk != NULL);

    free(list);
}
