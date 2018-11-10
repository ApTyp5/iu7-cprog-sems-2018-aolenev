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

    for (int i = index; i < list.size; i++)
        action(liu7st_get(list, i));

    return SUCCESS;
}
