#include "strIU7ng.h"

/*
 * Функция переворачивает строку и возвращает ее
 *
 * @param string [in]
 *
 * @return возвращается перевернутая строка
*/

void my_free(char **a)
{
    free(*a);
}

strIU7ng strIU7ng_reverse(strIU7ng string)
{
    if (string.head == NULL)
        return strIU7ng_create(NULL);

    if (string.len == 0)
        return strIU7ng_create("");

    char *result __attribute__ ((cleanup(my_free))) = malloc(string.len);

    if (result == NULL)
        return strIU7ng_create(NULL);

    for (int i = 0; i < string.len; i++)
        result[i] = string.head[string.len - i - 1];

    result[string.len] = '\0';
    
    return strIU7ng_create(result);    
}
