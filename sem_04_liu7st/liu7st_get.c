#include "liu7st.h"

void *get(liu7st list, int i, void *data)

{
    if (i < 0)
    {
        i = list.size + i;
    }
    
    if (i >= list.size)
    {
        return NULL;	
    }
    
    
    if(list.size - i < list.size / 2)
    {
        liu7st_element curr = *(list.first);

        for(int x = 0; x != i; x++)
        {
            curr = *curr.next;
        }
		
        return curr;	
	}
	
    else
    {
        liu7st_element curr = *(list.last);
   
        for(int x = 0; x != i; x++)
        {
            curr = *curr.prev;
        }
	
        return curr;
        }
        
        return NULL;
}