#include <stdlib.h>
#include "liu7st.h"

int liu7st_insert(liu7st *list, void *data, int i)
{
   if ((i < 0) || (i > list->size))
       return FAILED;
   
   if ((list->first == NULL) || (list->last == NULL))
       return FAILED;
   
   int count = 0;
   liu7st_element *sup = list->first;
   liu7st_element *node = malloc(sizeof(liu7st_element));
   node->data = data;
   node->prev = NULL;
   node->next = NULL;
   
   while (count < i - 1)
   {
       count++;
       sup = sup->next;    
   }
   
   if (i != 0)
   {
       node->prev = sup;
       
       if (i < size)
           sup = sup->next;
   }
   
   if (i < size)
   {
       node->next = sup;
       sup->prev = node;
   }
   
   if (i != 0)
   {
       if (i < size)
       {
           sup = sup->prev;
           sup = sup->prev;
       }
       
       sup->next = node;
   }
   
   list->size += 1;
   
   if (i == 0)
       list->first = node;
   if (i == size)
       list->last = node;
   
   return SUCCESS;
}
