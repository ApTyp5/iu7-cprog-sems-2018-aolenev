/**
 * \file strIU7ng.c
 * \brief Содержит функцию strIU7ng_concat()
 */

#include "strIU7ng.h"

/**
 * \fn strIU7ng strIU7ng_concat(strIU7ng str1, strIU7ng str2)
 * \brief Складывает две строки типа strIU7ng
 * \param [in] str1 Первая строка типа strIU7ng
 * \param [in] str2 Вторая строка типа strIU7ng
 * \return Сложенная строка типа strIU7ng
 */
strIU7ng strIU7ng_concat(strIU7ng str1, strIU7ng str2)
{
    int n = str1.len + str2.len;
    char str3[n + 1];

    if (str1.head == NULL || str2.head == NULL)
        return strIU7ng_create("");

    for (int i = 0; i < str1.len; i++)
        str3[i] = str1.head[i];

    for (int i = 0; i < str2.len; i++)
        str3[str1.len + i] = str2.head[i];

    str3[n] = '\0';

    return strIU7ng_create(str3);
}
