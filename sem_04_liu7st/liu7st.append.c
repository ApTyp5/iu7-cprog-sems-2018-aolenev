#include "liu7st.h"

/**
 * Appends element to the end of a list
 * \param [in] list
 * \param [in] data
 */
void liu7st_append(liu7st *list, void *data)
{
    liu7st_insert(list, data, list->size);
}
