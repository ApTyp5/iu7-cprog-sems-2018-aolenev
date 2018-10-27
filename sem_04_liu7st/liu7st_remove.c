#include "liu7st_remove.h"
#include "liu7st.h"

int liu7st_remove(striu7st *list, int i)
{
    if (i >= list->size || i < 0)
        return WRONG_INDEX;
    
    liu7st_element *p = list->first;
    
    if (!i)
    {
        // 
    }
    
    for (int a = 0; a < i - 1; a++)
        p = p->next;
    
    
}