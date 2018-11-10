#include "liu7st.h"

/*
 * \brief Функция выполняет action над всеми элементами, начиная с номера index
 *
 * \param [out] list - список
 * \param [in]  index - номер элемента, с которого начать
 * \param [in]  action - действие для элементов
 *
 * \return Возвращает SUCCESS при успешнов выполнении, WRONG_LIST при некорректном списке и
 * WRONG_INDEX при некорректном индексе
 */
int liu7st_apply(liu7st list, int index, void (*action)(void*))
{
    if (list.first == NULL || list.last == NULL)
        return WRONG_LIST;

    if (index >= list.size || index < 0)
        return WRONG_INDEX;

    if (index < list.size / 2)
    {
        liu7st_element *temp = list.first;

        for (int i = 0; i < index; i++)
            temp = temp->next;

        for (; temp != NULL; temp = temp->next)
            action(temp->data);
    }
    else
    {
        liu7st_element *temp = list.last;

        for (int i = list.size; i > index; i--)
        {
            action(temp->data);
            temp = temp->prev;
        }
    }

    return SUCCESS;
}
