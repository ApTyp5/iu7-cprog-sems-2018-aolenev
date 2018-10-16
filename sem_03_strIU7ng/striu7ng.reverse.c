#include "striu7ng.h"

/*
 * Функция переворачивает строку и возвращает ее
 *
 * @param string [in]
 *
 * @return возвращается перевернутая строка
*/

strIU7ng strIU7ng_reverse(strIU7ng string)
{
    if (string == NULL)
        return NULL;

    if (string.head == NULL)
        return NULL;

    if (string.len == 0)
        return strIU7ng_create("");

    char *result = malloc(string.len);

    if (result == NULL)
        return NULL;

    for (int i = 0; i < string.len; i++)
        result[i] = string.head[string.len - i - 1];
    
    return strIU7ng_create(result);    
}
