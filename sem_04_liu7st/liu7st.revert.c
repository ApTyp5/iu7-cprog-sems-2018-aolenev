#include "liu7st.h"

#define FREE_LIST 0

liu7st liu7st_revert(liu7st list)
{
    if (list.size == FREE_LIST)
        return list;
    
    if (list.first == NULL || list.last == NULL)
        return list;
    
    liu7st revert_list;
    liu7st_element *head;
    liu7st_element *tmp;
    
    revert_list.size = list.size;
    revert_list.first = list.last;
    revert_list.last = list.first;
    
    revert_list.first->next = revert_list.first->prev;
    revert_list.first->prev = NULL;
    
    revert_list.last->prev = revert_list.last->next;
    revert_list.last->next = NULL;
    
    head = revert_list.first->next;
    
    while (head != NULL)
    {
        tmp->next = head->prev;
        head->prev = head->next;
        head->next = tmp->next;
        
        head = head->next;
    }
    
    return revert_list;
}
