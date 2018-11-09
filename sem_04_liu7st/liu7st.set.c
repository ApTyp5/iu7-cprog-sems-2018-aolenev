#include "liu7st.h"

int liu7st_set(liu7st list, int i, void *data)
{
    if (list.first == NULL || list.last == NULL)
    {
        return SET_ERROR;
    }

    if (data == NULL)
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
        return SET_ERROR;
    }
    
    if (i < list.size / 2)
    {
        liu7st_element *curr = list.first;

        for (int x = 0; x != i; x++)
        {
            curr = curr->next;
        }
		
        curr->data = data;
        return SUCCESS;	
	}	
  else
  {
        liu7st_element *curr = list.last;
        i = list.size - i - 1;
        
        for (int x = 0; x != i; x++)
        {
            curr = curr->prev;
        }
	
        curr->data = data;
        return SUCCESS;
  }

  return  SET_ERROR;
}
