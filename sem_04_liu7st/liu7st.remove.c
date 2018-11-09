/**
 * \file liu7st_remove.c
 * \brief Содержит функцию liu7st_remove()
 */

#include "liu7st.h"

/**
 * \fn int liu7st_remove(striu7st *list, int i)
 * \brief Удаляет элемент списка 
 * \param [in] list Указатель на список
 * \param [in] i Индекс удаляемого элемента 
 * \return Код выполнения
 */
int liu7st_remove(liu7st *list, int i, void (*free_data)(void *))
{
    liu7st_element *p = list->first; //< Указатель на удаляемый элемент
    
    if (list == NULL)
        return WRONG_LIST;	
	
    if (i >= list->size || i < 0)
        return WRONG_INDEX;
    
    for (int a = 0; a < i; a++)
        p = p->next;
    
    if (i)
        (*(p->prev)).next = p->next;
    else
        (*list).first = p->next;
   
    if (i != list->size - 1)
        (*(p->next)).prev = p->prev;
    else
        (*list).last = p->prev;
    
    //free_data(p->data);
    //free(p);
    (*list).size--;
    
    return SUCCESS;
}