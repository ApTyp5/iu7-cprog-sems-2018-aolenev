#include "liu7st.h"
int set(liu7st list, int i, void *data)

{
    
    if (i < 0)
    {
        i = list.size + i;
    }
    
    if (i >= list.size)
    {
        return  SET_ERROR;	
    }
    
    if(list.size - i < list.size / 2)
    {
        liu7st_element curr = *(list.first);

        for(int x = 0; x != i; x++)
        {
            curr = *curr.next;
        }
		
        curr.data = data;
        return FREE_LIST;	
	}
	
    else
    {
        liu7st_element curr = *(list.last);
   
        for(int x = 0; x != i; x++)
        {
            curr = *curr.prev;
        }
	
        curr.data = data;
        return FREE_LIST;
        }
        
        return  SET_ERROR;
}