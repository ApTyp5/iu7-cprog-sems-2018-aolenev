#include "liu7st.h"

int liu7st_apply(liu7st list, int index, void (*action)(void*))
{
    if (list.first == NULL || list.last == NULL)
        return WRONG_LIST;

    if (index >= list.size || index < 0)
        return WRONG_INDEX;

    for (int i = index; i < list.size; i++)
        action(liu7st_get(list, i));

    return SUCCESS;
}
