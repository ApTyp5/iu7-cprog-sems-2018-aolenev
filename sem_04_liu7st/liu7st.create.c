#include "liu7st.h"

liu7st create()
{
    liu7st list;
    list.size = 0;
    list.first = malloc(sizeof(liu7st_element *));
    list.first = NULL;
    list.last = malloc(sizeof(liu7st_element *));
    list.last = NULL;

    return list; 
}
