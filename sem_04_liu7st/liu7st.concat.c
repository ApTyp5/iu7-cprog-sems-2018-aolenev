#include "liu7st.h"

liu7st liu7st_concat(liu7st first, liu7st second)
{
    liu7st result = liu7st_create();

    for (liu7st_element *el = first.first; el != NULL; el = el->next)
        liu7st_append(&result, el->data);

    for (liu7st_element *el = second.first; el != NULL; el = el->next)
        liu7st_append(&result, el->data);

    return result;
}
