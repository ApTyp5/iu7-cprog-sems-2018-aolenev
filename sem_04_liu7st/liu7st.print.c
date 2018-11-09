#include "liu7st.h"

int liu7st_print(liu7st list, void (*print_data)(const void*))
{
   if (list.first == NULL || list.last == NULL)
       return WRONG_LIST; 

    for (liu7st_element *temp = list.first;temp != NULL; temp = temp->next)
        print_data(temp->data);

    return SUCCESS;
}
