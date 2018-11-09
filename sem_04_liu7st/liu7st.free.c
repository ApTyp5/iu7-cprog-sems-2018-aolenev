#include "liu7st.h"

/*!Очищает память, выделенную для списка list. 
Память для элементов списка очищается при помощи функции free_data.

@param list [in, out]
@param free_data [in]

@return Ничего.
*/  

void liu7st_free(liu7st *list, void (*free_data)(void*))
{
    if (list->first == NULL || list->last == NULL || list->size == 0)
        return;

    liu7st_element *walk;

    walk = list->first;
    do
    {
        liu7st_element *tmp = walk;
        walk = walk->next;

        free_data(tmp->data);
        free(tmp);
    }
    while (walk != NULL);

    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}
