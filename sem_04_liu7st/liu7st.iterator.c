#include "liu7st.h"

#define OFFSET(STRUCT, MEMBER) (size_t)(&((STRUCT*)0)->MEMBER)

/**
 * Creates iterator pointing to the first list entry
 * \param [in] list
 * \retval NULL If list pointer is null
 * \retval iterator Otherwise
 */
void *liu7st_begin(liu7st *list)
{
    if (list == NULL)
        return NULL;

    return &list->first->data;
}

/**
 * Creates iterator pointing to the last list entry
 * \param [in] list
 * \retval NULL If list pointer is null
 * \retval iterator Otherwise
 */
void *liu7st_end(liu7st *list)
{
    if (list == NULL)
        return NULL;

    return &list->last->data;
}

/**
 * Moves iterator to the next list entry
 * \param [in] iterator
 * \retval NULL If iterator was already null or if there is no next entry
 * \retval new_iterator Otherwise
 */
void *liu7st_next(void *iterator)
{
    if (iterator == NULL)
        return NULL;

    liu7st_element *p = (liu7st_element*)((char*)iterator - OFFSET(liu7st_element, data));

    if (p->next == NULL)
        return NULL;

    return &p->next->data;
}

/**
 * Moves iterator to the previous list entry
 * \param [in] iterator
 * \retval NULL If iterator was already null or if there is no previous entry
 * \retval new_iterator Otherwise
 */
void *liu7st_prev(void *iterator)
{
    if (iterator == NULL)
        return NULL;

    liu7st_element *p = (liu7st_element*)((char*)iterator - OFFSET(liu7st_element, data));

    if (p->prev == NULL)
        return NULL;

    return &p->prev->data;
}
