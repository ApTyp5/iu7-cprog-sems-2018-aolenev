#include <liu7st.h>

/*!Очищает память, выделенную для списка list.

@param list [in, out]

@return Ничего.
*/

void liu7st_free(liu7st *list)
{
    if (list == NULL || list->first == NULL || list->last == NULL || size == 0)
        return;

    liu7st_element *walk;

    walk = list->first;
    do
    {
        liu7st_element tmp = walk;
        walk = walk->next;

        free(tmp->data);
        free(tmp);
    }
    while (walk != NULL);

    free(list);
}
