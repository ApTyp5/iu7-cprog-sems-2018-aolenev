#include "liu7st.h"

void liu7st_append(liu7st *list, void *data)
{
    liu7st_insert(list, data, list->size);
}
