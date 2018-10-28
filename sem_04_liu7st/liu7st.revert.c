#include "liu7st.h"

/**
 @file liu7st.revert.c
 @brief Переворачивает список.
 
 @param list [in] - структура с размером, указателями на первый и последний элементы списка
 
 @return Возвращает структуру с размером, указателями на первый и последний элементы
 перевернутого списка, если ошибок не было, иначе исходную структуру.
*/

liu7st liu7st_revert(liu7st list)
{
    // Проверка на пустой список
    if (list.size == FREE_LIST)
        return list;
    
    // Проверка на пустые указатели
    if (list.first == NULL || list.last == NULL)
        return list;
    
    liu7st revert_list;
    liu7st_element *head;
    void *tmp;
    
    revert_list.size = 2;
    revert_list.first = list.last;
    revert_list.last = list.first;
    
    // Меняются местами в первом и последнем элементах списка
    // указатели на следующий и предыдущий элементы
    revert_list.first->next = revert_list.first->prev;
    revert_list.first->prev = NULL;
    
    revert_list.last->prev = revert_list.last->next;
    revert_list.last->next = NULL;
    
    head = revert_list.first->next;
    
    // В каждом элементе списка меняются местами указатели
    // на следующий и предыдущий элементы, считается размер списка
    while (head->next != NULL)
    {
        if (head->prev == NULL)
            return list;
        
        tmp = head->prev;
        head->prev = head->next;
        head->next = tmp;
        
        head = head->next;
        ++(revert_list.size);
    }
    
    // Проверка полученного размера с ожидаемым
    if (revert_list.size != list.size)
        return list;
    
    return revert_list;
}
