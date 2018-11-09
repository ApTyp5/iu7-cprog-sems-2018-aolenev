#include "liu7st.h"

/*
 * \brief Вывод списка
 * \param [in] list - Список для вывода
 * \paran [in] print_data - Функция, которой происходит вывод элемента списка
 * \return WRONG_LIST - если список некорректный, SUCCESS - в случае вывода
 */

int liu7st_print(liu7st list, void (*print_data)(const void*))
{
   if (list.first == NULL || list.last == NULL)
       return WRONG_LIST; 

    for (liu7st_element *temp = list.first;temp != NULL; temp = temp->next)
        print_data(temp->data);

    return SUCCESS;
}
