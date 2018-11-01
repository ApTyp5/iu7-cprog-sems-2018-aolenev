#include "liu7st.h"

int set(liu7st list, int i, void *data)
{
    if (list == NULL && list->first == NULL && list->last == NULL)
    {
        return SET_ERROR;
    }
    

    
    if (i < 0)
    {
        i = list.size + i;
    }
    
    if (i >= list.size)
    {
        return  SET_ERROR;	
    }
    
    if (i < 0)
    {
        return NULL;
    }

    
    if (list.size - i < list.size / 2)
    {
        liu7st_element *curr = list->first;

        for (int x = 0; x != i; x++)
        {
            curr = curr->next;
        }
		
        curr->data = data;
        return SUCCESS;	
	}
	
    else
    {
        lliu7st_element *curr = list->last;
        i = list.size - i;
   
        for (int x = 0; x != i; x++)
        {
            curr = curr->prev;
        }
	
        curr->data = data;
        return SUCCESS;
    }
        
        return  SET_ERROR;
}