#include "liu7st.h"

liu7st liu7st_create()
{
    liu7st list;
    list.size = 0;
    list.first = NULL;
    list.last = NULL;

    return list; 
}
