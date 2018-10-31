#include <stdlib.h>
#include "liu7st.h"

/**
 @brief Функция добавляет элемент в список list по индексу i
 
 @param list [out]
 @param data [in]
 @param i [in]
 
 @return Функция возвращает SUCCESS в случае успешного завершения
 FAILED если входные данные были некорректны
 */
 
int liu7st_insert(liu7st *list, void *data, int i)
{
   if (list == NULL)
       return FAILED;
   
   if ((i < 0) || (i > list->size))
       return FAILED;
   
   if (((list->first == NULL) || (list->last == NULL)) && (list->size != 0))
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
       
       if (i < list->size)
           sup = sup->next;
   }
   
   if (i < list->size)
   {
       node->next = sup;
       sup->prev = node;
   }
   
   if (i != 0)
   {
       if (i < list->size)
       {
           sup = sup->prev;
           sup = sup->prev;
       }
       
       sup->next = node;
   }
   
   if (i == 0)
       list->first = node;
   if (i == list->size)
       list->last = node;
   
   list->size += 1;
   
   return SUCCESS;
}
