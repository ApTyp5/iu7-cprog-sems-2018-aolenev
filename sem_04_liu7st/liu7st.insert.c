#include <stdlib.h>
#include "liu7st.h"

int liu7st_insert(liu7st *list, void *data, int i)
{
   if ((i < 0) || (i > list->size))
       return FAILED;
   
   int count = 0;
   liu7st_element *sup = list->first;
   liu7st_element *node = malloc(sizeof(liu7st_element));
   node->data = data;
   
   while (count != i - 1)
   {
       count++;
       sup = sup->next;    
   }
   
   node->prev = sup;
   sup = sup->next;
   node->next = sup;
   sup->prev = node;
   sup = sup->prev;
   sup = sup->prev;
   sup->next = node;
   
   list->size += 1;
   
   return SUCCESS;
}