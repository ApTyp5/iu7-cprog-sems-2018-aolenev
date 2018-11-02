#include "liu7st.h"

/*
* \brief Получение элемента списка
* \param [in] list - Список, который принимается в качестве испытуемого. i -  индекс 
* \return data - элемент списка.
*/

void *liu7st_get(liu7st list, int i)
{
    if (list.first == NULL || list.last == NULL)
    {
        return NULL;
    }
    
    if (i < 0)
    {
        i = list.size + i;
    }
    
    if (i >= list.size)
    {
        return NULL;	
    }
    
    if (i < 0)
    {
        return NULL;
    }
    
    if (i < list.size / 2)
    {
        liu7st_element *curr = list.first;

        for (int x = 0; x != i; x++)
        {
            curr = curr->next;
        }
		
        return curr->data;	
	}
	
    else
    {
        liu7st_element *curr = list.last;
        i = list.size - i;
        
        for (int x = 0; x != i; x++)
        {
            curr = curr->prev;
        }
	
        return curr->data;
    }
        
    return NULL;
}